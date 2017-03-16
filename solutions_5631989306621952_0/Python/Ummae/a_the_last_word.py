import sys

rl = lambda: sys.stdin.readline().strip()


T = int(rl())
for tcase in range(T):
    s = rl()
    cc = [c for c in s]
    ret = []
    while cc:
        c, cc = cc[0], cc[1:]
        if ret and c >= ret[0]:
            ret = [c] + ret
        else:
            ret.append(c)
    print 'Case #%d: %s' % (tcase + 1, ''.join(ret))
