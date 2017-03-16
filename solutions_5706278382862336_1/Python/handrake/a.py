from fractions import gcd

sq = [2**x for x in range(41)]

def solve(p, q, n):
    # print p, q, n
    if q not in sq:
        return "impossible"
    if p == q or p > q:
        return n
    return solve(p, q/2, n+1)

for case in range(input()):
    p, q = [int(x) for x in raw_input().split('/')]
    g = gcd(p, q)
    p /= g
    q /= g
    print "Case #" + str(case + 1) + ":", solve(p, q, 0)
