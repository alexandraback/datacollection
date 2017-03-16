import sys
read = lambda f=int: list(map(f, sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

def solve(xs):
    res = 2000
    for m in range(1,max(xs)+1):
        c = cuts(m, xs)
        res = min(res, m+c)
    return res

def cuts(m, xs):
    return sum((x-1)//m for x in xs)

T, = read()
for t in range(T):
    _, = read()
    xs = read()
    print('Case #{}: {}'.format(t+1, solve(xs)))

# time = cuts + maxlen
# make all cuts first
# given max len, how many cuts are needed?
