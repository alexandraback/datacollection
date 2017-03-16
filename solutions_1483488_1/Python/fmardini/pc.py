import sys
import collections

def shifts(m):
    n = repr(m)
    d = collections.deque(n)
    res = []
    for _ in range(len(n) - 1):
        d.rotate(1)
        t = int("".join(d))
        if t > m: res.append(t)
    return list(set(res))

def solve(a, b):
    res = 0
    for n in xrange(a, b + 1):
        for m in shifts(n):
            if m <= b: res += 1
    return res

kases = int(sys.stdin.readline())
for k, l in enumerate(sys.stdin.readlines()):
    a, b = map(lambda n: int(n), l.strip().split(' '))
    print("Case #%d: %d" % (k + 1, solve(a, b)))
