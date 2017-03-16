from sys import stdin




def solve(a, w):
    w.sort()
    now = 0
    res = len(w)
    added = 0
    while True:
        while now < len(w) and w[now] < a:
            a += w[now]
            now += 1
        res = min(res, added + len(w) - now)
        if now == len(w):
            return res
        if a == 1:
            return res
        a += a-1
        added += 1



def rl():
    return [int(x) for x in stdin.readline().strip().split()]

t, = rl()
for tc in xrange(1, t + 1):
    a,n = rl()
    w = rl()
    print "Case #{0}: {1}".format(tc, solve(a, w))
