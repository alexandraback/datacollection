import fractions, math

denom = math.pow(2, 40)
for n in xrange(int(raw_input())):
    P, Q = map(int, raw_input().split('/'))
    gcd = fractions.gcd(P,Q)
    P = P / gcd; Q = Q / gcd
    if P < 0 or denom % Q != 0:
        print "Case #%d: %s" % (n+1, "impossible")
    else:
        print "Case #%d: %s" % (n+1, max(1, int(math.ceil(math.log(Q, 2) - math.log(P, 2)))))
        


