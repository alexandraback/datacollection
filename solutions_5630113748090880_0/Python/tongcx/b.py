from sys import stdin

T = int(stdin.readline())
for case in xrange(1, T+1):
    N = int(stdin.readline())
    cnt = {}
    ans = []
    for i in xrange(2*N-1):
        for x in map(int, stdin.readline().split()):
            cnt[x] = cnt.get(x, 0) + 1
    for x, c in cnt.iteritems():
        if c%2 == 1:
            ans.append(x)
    ans.sort()
    print 'Case #{}: {}'.format(case, ' '.join(map(str, ans)))
