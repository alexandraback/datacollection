import math
from fractions import gcd

def sol(A, B):
    g = gcd(A, B)
    a = A/g
    b = B/g
    pb = int(math.log(b, 2))
    pa = int(math.log(a, 2))
    if 1 << pb != b or a > b:
        return "impossible"
    r = pb - pa
    if r < 0 or r > 40:
        return "impossible"
    return r

import sys
readline = sys.stdin.readline

line = readline()
tn = int(line)
for i in xrange(1, tn + 1):
    A, B = map(int, readline().split("/"))
    print 'Case #{}: {}'.format(i, sol(A, B))
