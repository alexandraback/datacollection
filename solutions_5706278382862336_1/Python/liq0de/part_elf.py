from decimal import Decimal
import math
from fractions import Fraction

def isEven(number):
    return number % 2 == 0

twotofourty = math.pow(2,40)

def check(number):
    return Decimal(twotofourty*number)% 1 == 0



r = open("input","r")
lines = r.readlines()

w = open("output","w")

T = int(lines[0])

for f in range(1,T+1):
    p = Fraction(lines[f])
    if isEven(p.denominator) and p.numerator<p.denominator and p<=1 and check(p):
        ancestors = int(math.ceil(math.log((1/p),2)))
        if p==1:
            ancestors = 1
    else:
        ancestors = "impossible"
    w.write("Case #"+str(f)+": "+(str(ancestors))+ "\n")

w.close()
