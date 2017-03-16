import sys
#import numpy as np

def getInt(f):
    return int(f.readline().strip())

def getLine(f):
    return f.readline().strip()

def getInts(f):
    return [int(i) for i in f.readline().strip().split()]

#with open('/home/edgar/C.in') as f:
with sys.stdin as f:
    T = getInt(f)
    for t in xrange(1,T+1):
        N, J = getInts(f)
        assert N%2==0
        a = N//2
        assert J <= 2**(a-2)
        
        witness = ' '.join((str(i+1) for i in range(2,11) ))
            
        print 'Case #%d:' % t
        for i in xrange(J):
            factor = '1'+format(i, '0%db'%(a-2) )+'1'
            product = ''.join((c+c for c in factor))
            #verify...
            for base in range(2, 11):
                num = int(product, base=base)
                assert num%(base+1)==0
            print product, witness
        
        sys.stdout.flush()

