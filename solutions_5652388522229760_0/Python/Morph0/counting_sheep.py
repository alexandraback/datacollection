from sets import Set

INF = 1 << 30


def solve(N):
    def digits(num):
        digits = Set()
        while num > 0:
            digits.add(num % 10)
            num /= 10
        return digits

    current = N
    seen = Set()
    while True:
        seen = seen.union(digits(current))
        if len(seen) >= 10:
            break
        current += N
    return current

with open("counting_sheep.in") as fin:
    T = int(fin.readline())
    for t in xrange(T):
        N = int(fin.readline())
        ans = str(solve(N)) if N != 0 else "INSOMNIA"
        print "Case #%d: %s" % (t+1, ans)
