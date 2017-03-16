from fractions import gcd

def checkpow2(x):
    while x % 2 == 0: x /= 2
    return x == 1


def solve(num):
    p, q = map(int, raw_input().strip().split('/'))
    p, q = p / gcd(p, q), q / gcd(p, q)
    if checkpow2(q):
        ans = 1
        while p * (2 ** ans) < q: ans += 1
    else:
        ans = "impossible"
    print "Case #%d:" % num, ans

n = int(raw_input())
for i in xrange(n):
    solve(i+1)
