import sys

T = int(sys.stdin.readline().rstrip())

for caseno in range(T):
    P,Q = map(int,sys.stdin.readline().split('/'))

    depth = 0
    while P < Q and depth <= 40:
        P *= 2
        depth += 1

    if depth > 40:
        print "Case #%d: %s" % (caseno + 1, "impossible")
    else:
        min_depth = depth
        while P % Q != 0 and depth <=40:
            P *= 2
            depth += 1

        if depth > 40:
            print "Case #%d: %s" % (caseno + 1, "impossible")
        else:
            print "Case #%d: %d" % (caseno + 1, min_depth)
