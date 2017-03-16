import sys
import gmpy
import math
import numpy

def area(r,N):
    return 2*r +1 + (N-1)*(2*r+1)+2*(N-1)*N

def maxN(r,t):    
    return (-(2*r-1) + gmpy.mpz((4*r*r - 4*r + 1 + 8*t)).root(2)[0])/4

        
f= open(sys.argv[1])
cases = int(f.readline())
of = open(sys.argv[2],'w') #sys.stdout

for case in xrange(1, cases+1):
    r, t = [int(i) for i in f.readline().split()]
    N = maxN(r,t)
    of.write("Case #%s: %s\n"% (case, N))
