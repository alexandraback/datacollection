
def solve(n):
    if n == 0:
        return "INSOMNIA"
    seen = set()
    for i in xrange(1, 100):
        seen.update(str(i * n))
        if len(seen) == 10:
            return n * i
T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    solution = solve(N)
    print "Case #%i:" % i, solution
