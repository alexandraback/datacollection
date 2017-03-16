II = lambda: int(raw_input())
for t in range(1, II() + 1):
    print 'Case #%d:' % t,
    
    K,C,S = map(int, raw_input().split())
    n = (K + C - 1) / C
    if n > S:
        print 'IMPOSSIBLE'
    else:
        for i in range(n):
            x = 0
            for j in range(C):
                x += min(K-1, i*C + j) * K**j
            print x + 1,
        print
