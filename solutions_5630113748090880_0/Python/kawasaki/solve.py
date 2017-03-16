T = int(raw_input())
for t in xrange(T):
    N = int(raw_input())
    counts = {}
    for _ in xrange(2 * N - 1):
        xs = map(int, raw_input().split())
        for x in xs:
            counts[x] = counts[x] + 1 if x in counts else 1
    nums = []
    for x, c in counts.iteritems():
        if c % 2 == 1:
            nums.append(x)
    print 'Case #{}: {}'.format(t + 1, ' '.join(map(str, sorted(nums))))
