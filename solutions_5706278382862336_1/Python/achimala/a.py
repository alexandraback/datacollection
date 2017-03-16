from fractions import gcd
from math import log

def solve(p, q):
    d = gcd(p, q)
    if d != 1:
        return solve(p / d, q / d)

    if q & (q - 1) != 0:
        return False

    if p == 1:
        return log(q) / log(2)

    if p > q / 2:
        return 1

    return 1 + solve(p, q / 2)

T = int(raw_input())
for i in range(T):
    p, q = map(int, raw_input().split("/"))
    s = solve(p, q)
    if s is False:
        s = "impossible"
    else:
        assert s == int(s)
        s = int(s)
    print "Case #{}: {}".format(i + 1, s)

