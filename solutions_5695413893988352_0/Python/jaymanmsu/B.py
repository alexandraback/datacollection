T = int(raw_input().strip())

def possmatch(num, s):
    c = len(s) - 1
    while c >= 0:
        if s[c] == '?':
            c -= 1
            num = num/10
            continue
        if int(s[c]) != (num%10): return False
        num = num/10
        c -= 1
    return True

for t in range(T):
    C,J = raw_input().strip().split(' ')
    L = len(C)
    
    bestdiff = 1000
    bestC = 0
    bestJ = 0
    
    for c in range(int('1'+'0'*L)):
        if not possmatch(c, C): continue
        for j in range(int('1'+'0'*L)):
            if not possmatch(j, J): continue
            d = abs(c-j)
            if d < bestdiff:
                bestdiff = d
                bestC = c
                bestJ = j
    
    ans = ("%0"+str(L)+"d %0"+str(L)+"d") % (bestC, bestJ)
            
    # curC = '0'
    # curJ = '0'
    
    # for l in range(L):
        # cv = int(curC)
        # jv = int(curJ)
        # if cv == jv:
            # if C[l] == '?' and J['l'] == '?':
                # curC += '0'
                # curJ += '0'
                # continue
            # if C[l] == '?':
                # curC += J['l']
                

    print "Case #%d: %s" % (t+1, ans)