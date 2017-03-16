import sys

def getInt(f):
    return int(f.readline().strip())

def getLine(f):
    return f.readline().strip()

def getInts(f):
    return [int(i) for i in f.readline().strip().split()]

#with open('/home/edgar/D.in') as f:
with sys.stdin as f:
    T = getInt(f)
    for t in xrange(1,T+1):
        K, C, S = getInts(f)
        
        if C*S < K:
            print 'Case #%d: IMPOSSIBLE' % t
        else:
            ixs = []
            i = K
            while i > 0:
                ix = 0
                for j in range(C):
                    i = max(i-1, 0)
                    ix += i * K**j
                ixs.append(ix)
            assert len(ixs) <= S

            print 'Case #%d:' % t, ' '.join((str(i+1) for i in reversed(ixs)))
        
        sys.stdout.flush()

