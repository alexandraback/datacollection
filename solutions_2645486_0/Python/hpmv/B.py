def readline():
    return [int(x) for x in raw_input().split(' ')]

cases = readline()[0]

for v in range(cases):
    E,R,N=readline()
    if R>E: R=E
    tasks = readline()
    dp = [[-10**100]*(E+1) for _ in range(N+1)]
    dp[0][E]=0
    for i in range(1,N+1):
        for e in range(E+1):
            er = e+R
            if er > E: er=E
            for k in range(er+1):
                ne = er-k
                sc = dp[i-1][e]+k*tasks[i-1]
                if sc > dp[i][ne]:
                    dp[i][ne]=sc
    #print dp
    print "Case #%d: %d"%(v+1,dp[N][0])

