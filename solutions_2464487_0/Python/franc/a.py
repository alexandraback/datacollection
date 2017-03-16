from decimal import *
getcontext().prec = 100
getcontext().rounding=ROUND_FLOOR
T = int(raw_input())
for i in range(T):
    r, t = map(int, raw_input().split())
    a=2
    b=2*r-1
    c=-t
    sol=str(((Decimal(-b)+Decimal(b*b-4*a*c).sqrt())/Decimal(2*a)).to_integral_exact())
    print "Case #%d: %s" % (i+1, sol)

