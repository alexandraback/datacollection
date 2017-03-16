T = int(raw_input())
for loop in xrange(T):
    D = int(raw_input())
    P = map(int, raw_input().split())
    ans = max(P)
    P = [[p,1] for p in sorted(P)]

    for divide in xrange(1,1001):
        P[-1][1] += 1
        P = sorted(P, key = lambda x: x[0]/x[1] + (1 if x[0]%x[1] else 0))
        tmp = max(p/eat + (1 if p%eat else 0) for p ,eat in P) + divide
        ans = min(tmp, ans)
        
    print "Case #%d: %d"%(loop+1, ans)
