from fractions import gcd
import sys

def solve():
    a, b = map(int, sys.stdin.readline().strip().split('/'))
    g = gcd(a, b)
    a /= g
    b /= g
    ans = 0
    while b > 1:
        if b % 2 != 0:
            return 'impossible'
        b /= 2
        aa = a % 2
        a /= 2
        if aa:
            ans = 0
        else:
            ans += 1
    return ans + 1

T = int(sys.stdin.readline())
for i in xrange(1, T+1):
    print 'Case #%d:' % i, solve()