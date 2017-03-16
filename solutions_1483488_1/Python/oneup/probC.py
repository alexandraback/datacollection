import sys
import math

def num_digits(x):
    return math.ceil(math.log(x+1) / math.log(10))

def rotate(x,d):
    #print >>sys.stderr,x,d
    mod = 10**(d-1)
    return (x%mod)*10 + (x/mod)
        

def test(A,B):
    total = 0    
    d = 0
    x = A
    while x:
        d += 1
        x /= 10

    for n in xrange(A,B+1):
        #print >>sys.stderr,n
        m = rotate(n,d)
        while m != n:   #justifiable
            if A <= n < m <= B:
                #print >>sys.stderr,n,m
                total += 1
            m = rotate(m,d)
    return total
        
        
    
    

T = int(raw_input())
for t in xrange(T):
    A,B = map(int,raw_input().split())
    print >>sys.stderr, t
    print "Case #%d:" % (t+1), test(A,B)
