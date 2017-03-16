
C = None
J = None
CC = None
JJ = None
min_d = None

def diff(CC, JJ):
    return int(''.join(CC))-int(''.join(JJ))

def shrink():
    global C
    global J
    global CC
    global JJ
    global min_d
    l = len(C)
    newCC = []
    newJJ = []
    for i in range(l):
        newCC.append(CC[i])
        newJJ.append(JJ[i])

    if min_d < 0:
        # from most significant bit
        local_min_d = min_d
        for i in range(l):
            if C[i] == '?':
                newCC[i] = str(min(int(newCC[i]) + 1, 9))
                d = diff(newCC, newJJ)
                while abs(d) < abs(local_min_d):
                    local_min_d = d
                    CC[i] = newCC[i]
                    #print(CC)
                    #print(JJ)
                    newCC[i] = str(min(int(CC[i]) + 1, 9))
                    d = diff(newCC, newJJ)
                newCC[i] = CC[i]
    else:
        local_min_d = min_d
        for i in range(l):
            if J[i] == '?':
                newJJ[i] = str(min(int(JJ[i]) + 1, 9))
                d = diff(newCC, newJJ)
                while abs(d) < abs(local_min_d):
                    local_min_d = d
                    JJ[i] = newJJ[i]
                    #print(CC)
                    #print(JJ)
                    newJJ[i] = str(min(int(JJ[i]) + 1, 9))
                    d = diff(newCC, newJJ)
                newJJ[i] = JJ[i]

    return local_min_d


T = raw_input()
T = int(T)

for t_ in range(T):
    line = raw_input()
    C, J = line.split()
    l = len(C)
    Cu = []
    Ju = []
    CC = list(C)
    JJ = list(J)
    for i in range(l):
        if C[i] == '?':
            Cu.append(i)
            CC[i] = '0'
        if J[i] == '?':
            Ju.append(i)
            JJ[i] = '0'

    min_d = diff(CC, JJ)
    if min_d != 0:
        d = shrink()
        while abs(d) < abs(min_d):
            min_d = d
            if min_d == 0: break
            d = shrink()
    #print(min_d)

    CC = ''.join(CC)
    JJ = ''.join(JJ)
    print("Case #%d: %s %s" % (t_ + 1, CC, JJ))

    


"""
    for i in range(l-1):
        x = int(C[i+1])
        y = int(J[i+1])
        if C[i] == '?' and J[i] == '?':
            if x - y > 5:
                CC[i] = '0'
                JJ[i] = '1'
            elif y - x > 5:
                CC[i] = '1'
                JJ[i] = '0'
            else:
                CC[i] = '0'
                JJ[i] = '0'
        elif C[i] == '?':
            if y - x > 5:
                CC[i] = str(min(int(JJ[i])+1, 9))
            else:
                CC[i] = JJ[i]

"""
