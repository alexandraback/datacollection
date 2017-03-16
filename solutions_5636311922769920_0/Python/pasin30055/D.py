def findans(l, c, k):
    res = 0
    for i, j in enumerate(l):
        res += j * (k ** i)
    return res

tt = int(raw_input())
for t in xrange(tt):
    k, c, s = map(int, raw_input().strip().split())
    if k > c * s:
        ans = 'IMPOSSIBLE'
    else:
        ans = []
        for i in xrange(0, k, c):
            ans.append(findans(range(i, min((i + c), k)), c, k))
        ans = ' '.join([str(i + 1) for i in ans])
    print 'Case #' + str(t + 1) + ': ' + ans
