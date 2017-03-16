z = int(raw_input())
for casei in xrange(1, z+1):
    a, b, k = map(int, raw_input().split())
    res = 0
    for i in xrange(0, a):
        for j in xrange(0, b):
            if i & j < k:
                res += 1

    print 'Case #%d: %d' % (casei, res)
