from collections import defaultdict

T = int(raw_input())

for i in range(1, T+1):
    print 'Case #%d:' % i,
    N = int(raw_input())
    counts = defaultdict(int)
    for _ in range(2*N-1):
        nums = map(int, raw_input().split(' '))
        for num in nums:
            counts[num] += 1
    cnt = sorted(counts.iteritems())
    for x, y in cnt:
        if y % 2 == 1:
            print x,
    print
