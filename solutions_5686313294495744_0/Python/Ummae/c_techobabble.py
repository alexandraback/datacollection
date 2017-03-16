import sys

rl = lambda: sys.stdin.readline().strip()


T = int(rl())
for tcase in range(T):
    n = int(rl())
    topics = []
    for i in range(n):
        a, b = rl().split()
        topics.append((a, b))
    ans = 0
    print >> sys.stderr, tcase, n
    for i in range(1 << n):
        real, faked = [], []
        for b in range(n):
            if (i & (1 << b)):
                faked.append(b)
            else:
                real.append(b)
        if ans >= len(faked):
            continue
        real_first = set([topics[r][0] for r in real])
        real_second = set([topics[r][1] for r in real])
        fake_first = set([topics[f][0] for f in faked])
        fake_second = set([topics[f][1] for f in faked])
        if len(real_first & fake_first) == len(fake_first) and len(real_second & fake_second) == len(fake_second):
            ans = len(faked)

    print 'Case #%d: %s' % (tcase + 1, ans)
    # print acase
    # sys.exit()
