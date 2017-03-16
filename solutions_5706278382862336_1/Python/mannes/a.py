from fractions import *
import math

def solve(frac):
    d = frac.denominator
    e = int(math.log(d, 2))
    if d != 1 << e:
        return "impossible"
    elif e > 40:
        return "impossible"
    for i in range(1, 41):
        if Fraction(1, 2**i) <= frac:
            return i
        
        
    

f = file('a.in', 'r')
lines = f.readlines()
t = int(lines[0])
f.close()

g = file('a.out', 'w')

for i in xrange(t):
    s = solve( Fraction(lines[i+1].strip()) )
    g.write("Case #{}: {}\n".format(i+1, s))
g.close()
