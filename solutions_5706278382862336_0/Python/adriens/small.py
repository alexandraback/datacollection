import sys

import math
from fractions import Fraction


readline = sys.stdin.readline


T = int(readline())
        


def c(p,q):
    x  = round(math.log(q)/math.log(2))
#     print x
    if 2**x != q:
        print "Case #%i: impossible"%(t+1)
        return
    else:
        if p==1:
            print "Case #%i: %i"%(t+1,x)
            return
        else:
            for i in range(2,int(x)+1):
                if 2**(i-1)<p and p<2**i:
                    print "Case #%i: %i"%(t+1,x-i+1)
                    return
    
            


for t in range(T):
    p,q = readline().split('/')
    p = int(p)
    q = int(q)
    
    f = Fraction(p,q)
    p = f.numerator
    q = f.denominator
    

    c(p,q)    
    
            
    