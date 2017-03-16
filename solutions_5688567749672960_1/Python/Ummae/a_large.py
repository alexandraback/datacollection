import sys
rl = lambda: sys.stdin.readline().strip()

T = int(rl())
for tcase in range(1, T + 1):
    N = int(rl())
    print >> sys.stderr, tcase, N
    n = N
    ans = 0
    Q = [(n, 1)]
    while True:
        if n == 1:
            break
        rn = int(str(n)[::-1])
        sn = str(n)
        half = len(sn) / 2
        if half > 0 and int(sn[half:]) > 1:
            dec = int(sn[half:]) - 1
            n = n - dec
            ans += dec
        elif len(str(n)) == len(str(rn)) and rn < n:
            # print >> sys.stderr, '\tb', n, rn, 1, ans
            n = rn
            ans += 1
        else:
            # print >> sys.stderr, '\tc', n, n - 1, 1, ans
            n -= 1
            ans += 1
    print 'Case #%d: %d' % (tcase, ans + 1)
