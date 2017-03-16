T = int(raw_input())

for t in xrange(T):
    N, M, K = [int(x) for x in raw_input().split()]

    if N == 1 or M == 1: 
        print 'Case #%d: %d' %(t + 1, K)
        continue 

    stone = M * 2 + N * 2 - 4
    total = M * N

    while total >= K:
        #print N, M
        if (total - K) <= 4:
            delta = min(4, total - K)
            stone -= delta
            print 'Case #%d: %d' %(t + 1, stone)
            break

        if (total - K) >= min(N, M): 
            stone -= 2
            total -= min(N, M)
            #print total, stone
            if N > M:
                N -= 1
            else:
                M -= 1
        else:
            if N > 2 and M > 2:
                stone -= 4
            print 'Case #%d: %d' %(t + 1, stone)
            break
