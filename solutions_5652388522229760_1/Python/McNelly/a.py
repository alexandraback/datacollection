def solve(x):
    if x == 0:
        return 'INSOMNIA'
    xx = x
    s = set([])

    while True:
        s |= set(str(xx))
        if len(s) == 10:
            return xx
            break
        xx += x


T = int(raw_input())
for case_ in xrange(T):
    x = int(raw_input())
    ans = solve(x)
    print "Case #{}: {}".format(case_ + 1, ans)
