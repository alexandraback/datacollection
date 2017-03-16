T = input()
for test_case in xrange(1, T + 1):
    n = input()
    cnt = {}
    for i in xrange(2 * n - 1):
        for j in map(int, raw_input().split()):
            cnt[j] = cnt.get(j, 0) + 1
    res = []
    for i in cnt.keys():
        if cnt[i] % 2:
            res.append(i)
    print 'Case #%d: %s' % (test_case, ' '.join(map(str, sorted(res))))
