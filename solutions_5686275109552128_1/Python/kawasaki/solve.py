T = int(raw_input())
for t in xrange(T):
    D = int(raw_input())
    P = map(int, raw_input().split())

    candidates = []
    for n in xrange(1, max(P) + 1):
        count = 0
        for p in P:
            count += (p - 1) / n
        candidates.append(count + n)

    print 'Case #{}: {}'.format(t + 1, min(candidates))
