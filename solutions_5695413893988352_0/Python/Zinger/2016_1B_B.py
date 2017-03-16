import os

foldername = os.getcwd()
filename = "B-small-attempt2"
f_i = open(os.path.join(foldername, filename+".in"))
T = int(f_i.readline())

if os.path.isfile(filename+".out"):
    os.remove(filename+".out")
f_o = open(filename+".out", 'w')

for case in range(T):
    [C,J] = map(list,f_i.readline().split())
    digs = len(C)

    CC = C[:]
    CJ = C[:]
    JC = J[:]
    JJ = J[:]
    
    winner = 0
    for i in range(digs):
        if C[i] == '?' or J[i] == '?':
            continue
        elif C[i] == J[i]:
            continue
        else:
            if C[i] > J[i]:
                # assume C wins
                for j in range(i,digs):
                    if C[j] == '?':
                        CC[j] = '0'
                    if J[j] == '?':
                        JC[j] = '9'
                for j in range(i-1,-1,-1):
                    if C[j] == '?' and J[j] == '?':
                        CC[j] = '0'
                        JC[j] = '0'
                    elif C[j] == '?':
                        CC[j] = J[j]
                    elif J[j] == '?':
                        JC[j] = C[j]
                # assume J wins
                for j in range(i,digs):
                    if C[j] == '?':
                        CJ[j] = '9'
                    if J[j] == '?':
                        JJ[j] = '0'
                under = True
                for j in range(i-1,-1,-1):
                    if   under and C[j] == '9':
                        JJ[j] = '0'
                    elif under and J[j] == '0':
                        CJ[j] = '9'
                    elif under and C[j] == '?' and J[j] == '?':
                        CJ[j] = '0'
                        JJ[j] = '1'
                        under = False
                    elif under and C[j] == '?':
                        CJ[j] = str(int(J[j])-1)
                        under = False
                    elif under and J[j] == '?':
                        JJ[j] = str(int(C[j])+1)
                        under = False
                    elif C[j] == '?' and J[j] == '?':
                        CJ[j] = '0'
                        JJ[j] = '0'
                    elif C[j] == '?':
                        CJ[j] = J[j]
                    elif J[j] == '?':
                        JJ[j] = C[j]
            if C[i] < J[i]:
                # assume J wins
                for j in range(i,digs):
                    if J[j] == '?':
                        JJ[j] = '0'
                    if C[j] == '?':
                        CJ[j] = '9'
                for j in range(i-1,-1,-1):
                    if C[j] == '?' and J[j] == '?':
                        CJ[j] = '0'
                        JJ[j] = '0'
                    elif C[j] == '?':
                        CJ[j] = J[j]
                    elif J[j] == '?':
                        JJ[j] = C[j]
                # assume C wins
                for j in range(i,digs):
                    if C[j] == '?':
                        CC[j] = '0'
                    if J[j] == '?':
                        JC[j] = '9'
                under = True
                for j in range(i-1,-1,-1):
                    if   under and J[j] == '9':
                        CC[j] = '0'
                    elif under and C[j] == '0':
                        JC[j] = '9'
                    elif under and C[j] == '?' and J[j] == '?':
                        JC[j] = '0'
                        CC[j] = '1'
                        under = False
                    elif under and J[j] == '?':
                        JC[j] = str(int(C[j])-1)
                        under = False
                    elif under and C[j] == '?':
                        CC[j] = str(int(J[j])+1)
                        under = False
                    elif C[j] == '?' and J[j] == '?':
                        CC[j] = '0'
                        JC[j] = '0'
                    elif C[j] == '?':
                        CC[j] = J[j]
                    elif J[j] == '?':
                        JC[j] = C[j]
            break
    else: # tie
        for j in range(digs):
            if C[j] == '?' and J[j] == '?':
                CC[j] = '0'
                JC[j] = '0'
                CJ[j] = '0'
                JJ[j] = '0'
            elif C[j] == '?':
                CC[j] = J[j]
                CJ[j] = J[j]
            elif J[j] == '?':
                JC[j] = C[j]
                JJ[j] = C[j]
    CCi = int(''.join(CC))
    JCi = int(''.join(JC))
    CJi = int(''.join(CJ))
    JJi = int(''.join(JJ))
    
    if CCi-JCi >= 0 and JJi-CJi >= 0:
        if CCi-JCi < JJi-CJi:
            f_o.write("Case #{}: {} {}\n".format(case+1,''.join(CC),''.join(JC)))
        elif CCi-JCi > JJi-CJi:
            f_o.write("Case #{}: {} {}\n".format(case+1,''.join(CJ),''.join(JJ)))
        elif JCi < JJi:
            f_o.write("Case #{}: {} {}\n".format(case+1,''.join(CC),''.join(JC)))
        else:
            f_o.write("Case #{}: {} {}\n".format(case+1,''.join(CJ),''.join(JJ)))

    elif CCi-JCi >= 0:
            f_o.write("Case #{}: {} {}\n".format(case+1,''.join(CC),''.join(JC)))
    elif JJi-CJi >= 0:
            f_o.write("Case #{}: {} {}\n".format(case+1,''.join(CJ),''.join(JJ)))

f_i.close()
f_o.close()