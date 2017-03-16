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


def is_2pow(n):
    while True:
        if (n & 1) != 0:
            return False

        n /= 2
        if n == 1:
            break
    return True


T = int(rl())
for tcase in range(T):
    P, Q = map(int, rl().split('/'))
    P, Q = get_simple_frac(P, Q)
    ans = 1
    possible = True
    if not is_2pow(Q) and not (P == 1 and Q == 1):
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
