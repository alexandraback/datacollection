def f(n):
    if n == 0:
        return 'INSOMNIA'
    seen = set()
    i = 1
    while len(seen) < 10:
        next_n = i * n
        seen.update(map(int, str(next_n)))
        i += 1
    return next_n


T = int(raw_input())
for t in xrange(1, T + 1):
    n = int(raw_input())
    print "Case #{}: {}".format(t, f(n))