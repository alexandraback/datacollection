def case(N):
    if N == 0:
        return "INSOMNIA"
    seen = set(xrange(10))
    j = 1
    n = N
    while len(seen) != 0:
        for i in map(int, list(str(n))):
            seen.discard(i)
            if len(seen) == 0:
                return n
        j += 1
        n = j * N
    return N

if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(1, T + 1):
        N = int(raw_input())
        print "Case #%d: %s" % (i, case(N))
