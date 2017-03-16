from itertools import combinations

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    res = N
    tab=[N]*(N+1)
    tab[N] = 1
    for k in range(N-1, 0, -1):
        # print k
        s = str(k)
        rev = s[::-1]
        kk = int(rev)
        if kk>N:
            tabkk=N
        else:
            tabkk=tab[kk]
        tab[k] = 1+min(tab[k+1], tabkk)
        
    res = tab[1]
    print "Case #"+str(i+1)+": "+str(res)
