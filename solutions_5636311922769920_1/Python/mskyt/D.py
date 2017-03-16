import sys


def index( K, pos ):
    s = 0
    for p in pos:
        s = K*s + p
    return s

def solve( K, C, S ):
    if C*S < K:
        return None
    if K%C == 0:
        S = K/C
    else:
        S = K/C+1
    ret = []
    for s in xrange(S):
        pos = range(s*C,(s+1)*C)
        pos = [ p if p < K else 0  for p in pos ]
        pos.sort() # to generate minimal index
        ret.append( index(K, pos)+1 )
    return ret


def verify( K, C, S, sol ):
    if K == 1 or sol is None:
        return True
    ret = set()
    for s in sol:
        s -= 1
        for c in range(C):
            ret.add( s% K )
            s /= K
    if len(ret) != K:
        print K, C, S, sol, ret
        raw_input()

        
if __name__ == "__main__":
    fd = open( sys.argv[1] )
    T = int( fd.readline() )
    for t in xrange(T):
        p = fd.readline().split()
        s = solve( int(p[0]), int(p[1]), int(p[2]) )
        verify( int(p[0]), int(p[1]), int(p[2]), s )
        
        if s is None:
            print "Case #%d: IMPOSSIBLE" % (t+1)
        else:
            print "Case #%d: %s" % (t+1, " ".join("%d" % p for p in s))
    fd.close()

