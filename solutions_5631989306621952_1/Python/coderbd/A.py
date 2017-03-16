#!/usr/bin/python

t = int(raw_input())
for case_no in xrange(1, t+1):
    s = raw_input()
    n = len(s)
    ans = s[0]
    for i in xrange(1, n):
        if s[i] >= ans[0]:
            ans = s[i] + ans
        else:
            ans = ans + s[i]
    print 'Case #%d: %s' % (case_no, ans)