T = int(raw_input())

powers = [1]
for i in xrange(1, 41):
    powers.append(powers[-1]*2)

def gcd(a, b):
    if a < b: return gcd(b, a)
    if b == 0: return a
    return gcd(b, a%b)

def red(num, denom):
    g = gcd(num, denom)
    return num/g, denom/g

for ll in xrange(1, T+1):
    p, q = map(long, raw_input().split('/'))
    p, q = red(p, q)
    if q in powers:
        for ind, n in enumerate(powers):
            if n*p >= q:
                ans = ind
                break
    else:
        ans = "impossible"
    print "Case #%d: %s" % (ll, ans)
