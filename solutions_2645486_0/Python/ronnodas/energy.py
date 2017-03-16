T = int(input())

for case in range(1,T+1):
    E,R,N = [int(x) for x in input().split()]
    vs = [int(x) for x in input().split()]
    
    DP = [[0]*(E+1) for i in range(N+1)]
    
    for i in range(N-1,-1,-1):
        for e in range(E+1):
            for spe in range(0,e+1):
                DP[i][e] = max(DP[i][e],vs[i]*spe+DP[i+1][min(e-spe+R,E)])
    ans = DP[0][E]

    print('Case #',case,': ',ans,sep='')
