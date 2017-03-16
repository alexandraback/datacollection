T = input()

for CN in xrange(1, T+1):
    A, B, K = [int(i) for i in raw_input().split()]

    ans = 0
    for x in xrange(A):
        for y in xrange(B):
            if (x & y) < K:
                ans += 1
    print "Case #%d: %d" % (CN, ans)

