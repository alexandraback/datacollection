T = input()
for test_case in xrange(1, T + 1):
    n = input()
    a = map(lambda x: int(x) - 1, raw_input().split())
    ans = [0] * n
    res = 0
    for i in xrange(n):
        if a[a[i]] == i:
            ans[i] = max(ans[i], 2)
        hsh = [False] * n
        cur = i
        cnt = 0
        cycle = []
        while not hsh[cur]:
            cycle.append(cur)
            cnt += 1
            hsh[cur] = True
            cur = a[cur]
        #print cycle, a[cycle[-1]]
        if a[cycle[-1]] == i:
            res = max(res, len(cycle))
        else:
            ans[cycle[-1]] = max(ans[cycle[-1]], len(cycle))
            #print cycle[-1], ans[cycle[-1]]
    #print ans, res
    tmp = 0
    for i in xrange(n):
        #print i, a[i], a[a[i]], i == a[a[i]]
        if i == a[a[i]] and i < a[i]:
            tmp += max(ans[i], ans[a[i]], ans[i] + ans[a[i]] - 2)
    print 'Case #%d: %d' % (test_case, max(res, tmp))
