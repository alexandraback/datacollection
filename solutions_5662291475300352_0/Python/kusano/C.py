T = input()
for t in range(T):
    N = input()
    D = []
    M = []
    for i in range(N):
        d,h,m = map(int, raw_input().split())
        for j in range(h):
            D += [d]
            M += [m+j]
    if len(D)==1:
        ans = 0
    elif len(D)==2:
        t1 = M[0]*(360-D[0])
        t2 = M[1]*(360-D[1])
        if t1<t2:
            if t2/M[0] + D[0]>=720:
                ans = 1
            else:
                ans = 0
        else:
            if t1/M[1] + D[1]>=720:
                ans = 1
            else:
                ans = 0
    else:
        ans = 0
    print "Case #%s: %s"%(t+1, ans)
