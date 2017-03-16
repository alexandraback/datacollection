from fractions import gcd
from math import log
N = int(input())
for I in range(1, N+1):
    a, b = [int(x) for x in input().split('/')]
    g = gcd(a, b)
    a = a // g
    b = b // g
    t = int(log(b, 2))
    if 2**t != b:
        result = "impossible"
        print("Case #%d: %s" % (I, str(result)))
        continue
    result = t - int(log(a, 2))
    if (result < 1):
        result = "impossible"
    print("Case #%d: %s" % (I, str(result)))


