def solve(s):
    s += '+'
    return sum(c != d for c, d in zip(s[:-1], s[1:]))

T = int(raw_input())
for t in xrange(T):
    print "Case #%d: %d" % (t + 1, solve(raw_input().strip()))
