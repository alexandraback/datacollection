

T = input()

for case in range(1, T + 1):
    print "Case #%d:"%case,
    K, C, S = map(int, raw_input().split())
    if S * C < K:
        print "IMPOSSIBLE"
        continue
    for i in range(0, K, C):
        tot = 0
        for j in range(i, min(K, i + C)):
            tot = tot * K + j
        print tot + 1,
    print 
