import sys
from fractions import gcd
rl = lambda: sys.stdin.readline().strip()


def get_simple_frac(a, b):
    while True:
        c = gcd(a, b)
        if c >= 2:
            a /= c
            b /= c
        else:
            break
    return a, b


T = int(rl())
for tcase in range(T):
    P, Q = map(int, rl().split('/'))
    P, Q = get_simple_frac(P, Q)
    '''
    ans = 1
    possible = True
    if int(str(Q)[-1]) % 2 != 0 and not (P == 1 and Q == 1):
        possible = False
    else:
        for i in range(1, 41):
            n = pow(2, i)
            if float(P) / float(Q) >= 1.0 / float(n):
                break
            else:
                ans += 1

    if possible:
        print 'Case #%d: %d' % (tcase + 1, ans)
    else:
        print 'Case #%d: %s' % (tcase + 1, 'impossible')
    '''

    ans = 1
    possible = False
    al = set([(0, 0), (1, 1)])
    for i in range(10):
        aal = set()
        for a in al:
            for b in al:
                if a[1] == 0 and b[1] != 0:
                    c = get_simple_frac(b[0], b[1] * 2)
                elif b[1] == 0:
                    c = get_simple_frac((a[0] * b[1] + b[0] * a[1]), a[1] * b[1] * 2)
                else:
                    c = get_simple_frac((a[0] * b[1] + b[0] * a[1]), a[1] * b[1] * 2)
                aal.add(c)
        al = aal
        if (P, Q) in al:
            possible = True
            break

    for i in range(1, 41):
        n = pow(2, i)
        if float(P) / float(Q) >= 1.0 / float(n):
            break
        else:
            ans += 1

    if possible:
        print 'Case #%d: %d' % (tcase + 1, ans)
    else:
        print 'Case #%d: %s' % (tcase + 1, 'impossible')
