def f(k, r):
    return 2 * k * k + (2 + 2 * r - 3) * k

def solve(r, t):
    lb = 0
    ub = 1
    while f(ub, r) < t:
        ub *= 2
    while lb < ub:
        m = (ub - lb + 1) / 2 + lb
        x = f(m, r)
        if x < t:
            lb = m
        elif x > t:
            ub = m - 1
        else:
            return m
    return lb


ntc = int(raw_input())
for tc in range(ntc):
    rts = raw_input().strip().split()
    r = long(rts[0])
    t = long(rts[1])
    sol = solve(r, t)
    print "Case #%d: %d" % (tc + 1, sol)

