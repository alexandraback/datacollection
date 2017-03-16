from library import *
from math import sqrt

f = file('a.in2','r')
T = readint(f)
for case in range(1,T+1):
    r,t = readints(f)
    ins = (1-2*r)**2 + 8*t
    n = int((1-2*r + sqrt(ins))/4) - 1
    while 2*n*n-n+2*r*n <= t:
        n = n+1
    n = n-1
    print 'Case #%d: %d' % (case, n)


