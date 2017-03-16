import sys

def get_int(): return int(sys.stdin.readline())
def get_ints(): return [int(s) for s in sys.stdin.readline().split()]

def isqrt(n):
    x = n
    y = (x + n // x) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

t = get_int()
for i in range(t):
    [r, t] = get_ints()
    disc = (2*r-1)*(2*r-1) + 8*t
    dsqr = isqrt(disc)
    n = (-(2*r-1) + dsqr) // 4;
    print("Case #{0}: {1}".format(i+1, n))
