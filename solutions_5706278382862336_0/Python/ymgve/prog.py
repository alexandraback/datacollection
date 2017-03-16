import sys

import psyco; psyco.full()

def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x
    
def main():
    pows = [1]
    for i in xrange(1, 41):
        pows.append(pows[i-1] * 2)
        
    #print pows
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        a,b = f.readline().strip("\r\n").split("/")
        a = int(a)
        b = int(b)
        
        t = gcd(a,b)
        a = a / t
        b = b / t
      
        if b not in pows:
            res = "impossible"
        else:
            res = str(b)
        
            midpoint = b / 2
            while midpoint > a:
                midpoint /= 2
                
            #print midpoint, a, b
            #res = str(pows.index(midpoint))
            res = str(pows.index(b / midpoint))
        print "Case #%d: %s" % (caseno+1, res)
        
main()