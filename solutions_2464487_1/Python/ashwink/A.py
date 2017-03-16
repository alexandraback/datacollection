from math import sqrt, floor, pow
import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    (r, t) = [int(i) for i in f.readline().split()]
    rings = floor((1 - 2*r + sqrt( (2*r-1)**2 + 4*2*t ))/4)
    
    test = 2 * rings**2 + rings * (2*r - 1)
    if test > t:
        rings -= 1
        
    print "Case #%d: %d" % (case + 1, rings)
