if __name__ == '__main__':
    Tn = int(raw_input())
    for Tc in xrange(1, Tn + 1):
        E, R, N = map(int, raw_input().split())
        if R > E:
            R = E
        v = map(int, raw_input().split())
        INF = 2**60
        f = [[-INF for j in range(E+1)] for i in range(N+1)]
        f[0] = [0]*(E+1)
#         f[0][E] = 0
        
#         for i in range(1, N+1):
#             for j in range(R,E+1):
#                 vals = [f[i-1][k]+(k-(j-R))*v[i-1] for k in range(R,E+1)]
#                 f[i][j] = max(vals)
#             for j in range(R,E):
#                 f[i][j] = max(f[i][j], f[i][j+1])
        for i in range(1, N+1):
            for j in range(R,E+1):
                vals = [f[i-1][j+k-R]+k*v[i-1] for k in range(0,E+1) if E>=j+k-R>=0]
                f[i][j] = max(vals)
        ans = max(f[N])        
        print 'Case #%d: %d' % (Tc, ans)
