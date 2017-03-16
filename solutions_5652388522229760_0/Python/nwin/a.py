def solve(n):
    if n == 0:
        print "INSOMNIA"
        return
    s = set()
    t = 0
    while len(s) < 10:
        t += n
        s |= set(str(t))
    print t

T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t + 1),
    solve(int(raw_input()))
