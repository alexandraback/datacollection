T = input()
for test_case in xrange(1, T + 1):
    s = raw_input()
    ans = ''
    for i in s:
        ans = max(ans + i, i + ans)
    print 'Case #%d: %s' % (test_case, ans)
