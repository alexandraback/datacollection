import sys,math
from decimal import *

getcontext().prec = 100
f = open(sys.argv[1],'r')
n = int(next(f))

def count_rings(r,t):
    R = Decimal(r)
    T = Decimal(t)
    return ((1-2*R+((2*R-1)*(2*R-1)+8*T).sqrt())/4).to_integral_value(ROUND_DOWN)

for i in range(n):
    try:
        a = next(f).split(" ")
        print("Case #%d: %s"%(i+1,count_rings(int(a[0]),int(a[1]))))
    except: 
        pass
