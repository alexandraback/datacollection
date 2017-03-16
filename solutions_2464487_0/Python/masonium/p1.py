import math
import sys

def isqrt(n):
    x = n
    y = (x + n // x) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

def read_int_list():
    x = [int(x) for x in sys.stdin.readline().strip().split()]
    return x

def solve(r, t):
    a = 2
    b = 2 * r - 1
    c = -t

    disc = b*b - 4 * a *c

    sdisc = isqrt(disc)
    if sdisc*sdisc != disc:
        #print "not a perfect square"
        sdisc = math.sqrt(disc)

    n = (-b + sdisc) / (2 * a);

 #   print t
    d = a * n * n + b * n + c
    dm = a * (n-1)* (n-1) + b * (n-1) + c
    dp = a * (n+1)* (n+1) + b * (n+1) + c
#    print dm, d, dp
    
    if dm < 0.02 < d:
        return max(n-1, 1)
    
    return max(n, 1)

def main():
    t = read_int_list()[0]
    for x in range(1, t+1):
        r, t = read_int_list()
        print "Case #%d: %d" % (x, int(solve(r, t)))

if __name__ == "__main__":
    main()
