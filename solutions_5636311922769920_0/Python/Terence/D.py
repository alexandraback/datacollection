t = int(raw_input())
for icase in range(1, t+1):
    k, c, s = map(int, raw_input().split())
    if s*c < k:
        print 'Case #%d: IMPOSSIBLE' % icase
    else:
        res = []
        i = -1
        while i < k-1:
            rx = 0
            for j in range(c):
                if i < k-1:
                    i += 1
                rx = rx * k + i
            res.append(rx+1)
        print 'Case #%d: %s' % (icase, ' '.join(map(str, res)))
