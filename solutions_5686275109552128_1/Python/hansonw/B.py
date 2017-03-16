T = int(raw_input())

for i in xrange(T):
    raw_input()
    P = map(int, raw_input().split())
    max_elem = max(P)
    best = None
    for steps in xrange(1, max_elem + 1):
        result = steps - len(P)
        for x in P:
            result += (x + (steps - 1)) // steps
        if result < best or best == None:
            best = result
    print "Case #%d: %d" % (i+1, best)
