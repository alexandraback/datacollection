#!/usr/bin/python

t = int(raw_input())
for case_no in xrange(1, t+1):
    n = int(raw_input())
    m = 2 * n - 1
    count = {}

    for i in xrange(m):
        heights = map(int, raw_input().split())
        for height in heights:
            count[height] = count.get(height, 0) + 1

    ans = []
    for height, num in count.iteritems():
        if num % 2 == 1:
            ans.append(height)
    ans.sort()

    print 'Case #%d: %s' % (case_no, " ".join(map(str, ans)))