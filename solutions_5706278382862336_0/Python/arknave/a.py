T = int(raw_input())

powers = [1]
for i in xrange(1, 41):
    powers.append(powers[-1]*2)

def red(num, denom):
    # if I ever get to the hard version
    return num, denom

for ll in xrange(1, T+1):
    p, q = map(long, raw_input().split('/'))
    p, q = red(p, q)
    # Solving the small first - return impossible denom is not power of two
    if q in powers:
        for ind, n in enumerate(powers):
            if n*p >= q:
                ans = ind
                break
    else:
        ans = "impossible"
    print "Case #%d: %s" % (ll, ans)
