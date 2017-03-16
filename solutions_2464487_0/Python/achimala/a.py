from decimal import Decimal, getcontext

getcontext().prec = 100

def f(r,t):
    a = Decimal(-2)
    b = Decimal(-2) * Decimal(r) + Decimal(1)
    c = Decimal(t)
    # b = -(2.*r-1)
    # c = t
    half = Decimal(.5)
    n1 = (-b + (b*b - Decimal(4)*a*c)**half)/(Decimal(2)*a)
    n2 = (-b - (b*b - Decimal(4)*a*c)**half)/(Decimal(2)*a)
    return int(max(n1,n2))

N = int(raw_input())
for case in range(1,N+1):
    r, t = map(int, raw_input().split())
    print "Case #{}: {}".format(case, f(r,t))