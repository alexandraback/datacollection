from fractions import gcd

T = int(raw_input().strip())
two_pows = [2 ** i for i in xrange(1, 41)]

for i in xrange(1, T + 1):
    P, Q = map(int, raw_input().strip().split('/'))
    g = gcd(P, Q)
    P, Q = P / g, Q / g

    if Q not in two_pows:
        print "Case #%s: impossible" % i
        continue

    ans = 0
    while P < Q:
        Q /= 2
        ans += 1
    print "Case #%s: %s" % (i, ans)
