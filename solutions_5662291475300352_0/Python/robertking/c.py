from fractions import Fraction as f

data = iter(open('C-small-1-attempt0.in').read().splitlines())
cases = int(next(data))



def solve(deer):
    if len(deer) == 1:
        d, h, m = deer[0]
        if h == 1:
            return 0
        d1, m1 = d, m
        d2, m2 = d, m + 1
    else:
        d1, _, m1 = deer[0]
        d2, _, m2 = deer[1]
    d1 = 360 - d1
    d2 = 360 - d2
    t1 = f(d1 * m1, 360)
    t2 = f(d2 * m2, 360)
    t1b = f((360 + d1) * m1, 360)
    t2b = f((360 + d2) * m2, 360)
    if t2 < t1:
        t1, t2 = t2, t1
        t1b, t2b = t2b, t1b
    #arrive at t2 (slower time)
    if t2 < t1b:
        return 0
    return 1

for case in range(1, cases + 1):
    n = int(next(data))
    deer = []
    for _ in range(n):
        d, h, m = map(int, next(data).split())
        deer.append((d, h, m))
    print "Case #%d: %d" % (case, solve(deer))


