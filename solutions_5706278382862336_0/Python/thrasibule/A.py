import sys
from fractions import gcd

def msb(n):
    k = 0
    n = n>>1
    while n!=0:
        n = n>>1
        k += 1
    return k

with open(sys.argv[1]) as fh:
    T = int(fh.readline())
    for i in range(T):
        n, d  = map(int, fh.readline().split("/"))
        g = gcd(n, d)
        n /= g
        d /= g
        if d & (d-1) == 0:
            print "Case #{0}: {1}".format(i+1, msb(d)-msb(n))
        else:
            print "Case #{0}: {1}".format(i+1, "IMPOSSIBLE")
