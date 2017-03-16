for tc in xrange(input()):
    n = input()
    counts = {}
    for i in xrange(2*n-1):
        nums = [int(j) for j in raw_input().strip().split()]
        for j in nums:
            if j not in counts:
                counts[j] = 0
            counts[j] += 1
    ans = sorted([i for i in counts if counts[i]&1])
    ans = ' '.join([str(i) for i in ans])
    print "Case #%d: %s" % (tc+1, ans)
