
#============================================

def readBuffer():
#    '''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """5
-
-+
+-
+++
--+-
-+--++-
    """.split("\n");
    #'''
    
    t = int(buf[0]); buf=buf[1:];
    
    buf = filter(lambda x: x[0] == '-' or x[0] == '+', buf);
    
    return buf;

def depth(S,n):
    q = deque([(0,n)]);

    visited = set();
    while len(q) > 0:
        d,n = q.popleft();
        if n == 0: return d;
        if n in visited: continue;
        visited.add(n);

        for i in xrange(S):
            arr = [ int((n & (1<<j))>0) for j in xrange(S-i) ];
            flip = sum( (1-x)<<j for j,x in enumerate(reversed(arr)) );
            msk = ~((1<<(S-i))-1);
            nn = n & msk;
            nn |= flip;
            if nn in visited: continue;
            q.append((d+1,nn));

def solveProblem((rnd,x)):
    S = len(x);
    x = map(lambda z: 1 if z == '-' else 0, x);
    x = sum( z<<i for i,z in enumerate(x) );

    print rnd, (S,x);
    return depth(S,x);

#============================================

from collections import deque;
from time import time;

if __name__ == '__main__':
    infile = "B-small-attempt0.in";
    #infile = "B-large.in";
    outfile = "B.out";

    buf=readBuffer();
    start=time();
    with open(outfile,"wt") as f:
        res = map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
