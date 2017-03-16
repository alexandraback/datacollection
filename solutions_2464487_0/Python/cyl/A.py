import sys
import math
import decimal

T = int(sys.stdin.readline())

for i in range(T):

    r, t = sys.stdin.readline().strip().split(' ')
    r = int(r)
    t = int(t)
    #r = decimal.Decimal(r)
    #t = decimal.Decimal(t)
    #delta = (2*r-1)*(2*r-1) - 4*2*(-t)
    #delta = delta.sqrt()
    #ret = (-(2*r-1)+delta)/(2*2)
    #print r, t, delta, ret
    


    a = 2
    b = (2*r-1)
    c = -t
    d = b*b - 4*a*c
    k = (-(2*r-1)+math.sqrt((2*r-1)*(2*r-1) - 4*2*(-t)))/(2*2)
    
    #print r, t, a, b, c, d, k

    print "Case #" + str(i+1) + ": " + str(int(math.floor(k)))
