import sys
from itertools import product

rl = lambda: sys.stdin.readline().strip()


def generate_all(s):
    nq = s.count('?')
    if nq < 1:
        return [s]
    ret = []
    digit = [str(i) for i in range(10)] * nq
    for cmb in product(digit, repeat=nq):
        ss = s[::]
        while cmb:
            ss = ss.replace('?', cmb[0], 1)
            cmb = cmb[1:]
        ret.append(ss)
    ret.sort()
    return ret


T = int(rl())
for tcase in range(T):
    a, b = rl().split()
    print >> sys.stderr, tcase, a, b
    acase = generate_all(a)
    bcase = generate_all(b)
    min_abs = 100000000000
    ans = None
    for a in acase:
        for b in bcase:
            if abs(int(a) - int(b)) < min_abs:
                min_abs = abs(int(a) - int(b))
                ans = (a[::], b[::])
        if min_abs == 0:
            break

    print 'Case #%d: %s %s' % (tcase + 1, ans[0], ans[1])
    # print acase
    # sys.exit()
