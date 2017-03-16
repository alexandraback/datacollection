T = int(raw_input().strip())

for i in xrange(T):
    A, N = map(int, raw_input().strip().split(' '))
    motes = sorted(map(int, raw_input().strip().split(' ')))

    bottom = 0
    for mote in motes:
        if mote < A:
            A += mote
            bottom += 1
        else:
            break
    if bottom == N:
        print "Case #%s: %s" % (i + 1, 0)
        continue

    max_need = N - bottom
    need = 0
    best = max_need

    while need < max_need and bottom < N:
        need += 1
        A = 2 * A - 1
        while bottom < N and motes[bottom] < A:
            A += motes[bottom]
            bottom += 1
        best = min(best, need + N - bottom)

    print "Case #%s: %s" % (i + 1, best)
