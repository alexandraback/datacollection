T = int(raw_input())

for t in xrange(T):
    N = int(raw_input())
    bffs = map(int, raw_input().split())
    best = 0
    best_chain = [0] * N
    for i in xrange(N):
        seen = set()
        cur = i
        prev = -1
        length = 0
        while True:
            if cur in seen:
                break
            if prev != bffs[cur] - 1:
                best_chain[cur] = max(best_chain[cur], length)
            length += 1
            seen.add(cur)
            prev = cur
            cur = bffs[cur] - 1
        if cur == i:
            best = max(best, length)

    chains = 0
    for i in xrange(N):
        bff = bffs[i] - 1
        if bffs[bff] - 1 == i:
            chains += 1 + best_chain[i]

    best = max(best, chains)
    print 'Case #%d: %d' % (t+1, best)
