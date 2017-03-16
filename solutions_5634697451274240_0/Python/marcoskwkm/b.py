def solve(mask, n):
    dist = {}
    dist[mask] = 0
    queue = []
    queue.append(mask)
    at = 0
    while at < len(queue):
        cur = queue[at]
        at += 1
        bits = []
        d = dist[cur]
        for i in xrange(n):
            bits.append(1 if (cur & (1 << i)) > 0 else 0)
        for i in xrange(n):
            nxtbits = [0 for j in xrange(n)]
            for j in xrange(i + 1):
                nxtbits[j] = (bits[i - j] ^ 1)
            for j in xrange(i + 1, n):
                nxtbits[j] = bits[j]
            nxt = 0
            for i in xrange(n):
                if nxtbits[i] == 1:
                    nxt += (1 << i)
            if nxt in dist:
                continue
            dist[nxt] = d + 1
            queue.append(nxt)
    return dist[(1 << n) - 1]

T = int(raw_input())
for t in xrange(1, T + 1):
    pancakes = raw_input()
    n = len(pancakes)
    mask = 0
    for i in xrange(n):
        if pancakes[i] == '+':
            mask += (1 << i)
    print "Case #%d: %d" % (t, solve(mask, n))
