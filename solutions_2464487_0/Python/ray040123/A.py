import math

def solve(a, b, c):
    d = math.sqrt(b * b - 4 * a * c)
    t1 = (-b - d) / (2 * a)
    t2 = (-b + d) / (2 * a)
    if t1 > 0: return t1
    return t2

T = int(raw_input())
for i in xrange(T):
    r, t = map(int, raw_input().split())
    n = solve(2, 2 * r - 1, - t)
    print 'Case #{}: {}'.format(i + 1, int(math.floor(n)))
