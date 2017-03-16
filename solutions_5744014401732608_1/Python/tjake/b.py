for t in xrange(input()):
    print "Case #%d:"%(t+1),
    b, m = map(int, raw_input().split())
    if 2**(b-2) < m:
        print "IMPOSSIBLE"
        continue

    mat = [[int(i < j) for j in xrange(b)] for i in xrange(b)]
    res = 2**(b-2)

    for i in xrange(b-3, -1, -1):
        if res-m >= 2**i:
            res -= 2**i
            mat[i+1][b-1] = 0
    print "POSSIBLE"
    for i in xrange(b):
        print "".join(map(str, mat[i]))
