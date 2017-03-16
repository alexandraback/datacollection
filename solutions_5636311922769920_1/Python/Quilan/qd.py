
#============================================

def readBuffer():
#    '''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3""".split("\n");
    #'''

    t = int(buf[0]); buf=buf[1:];
    buf2 = [];
    for _ in xrange(1,t+1):
        K,C,S = parse(buf[0],"iii"); buf=buf[1:];
        buf2.append([K, C, S]);
        pass;
    return buf2;

def solveProblem((rnd,x)):
    ## Do actions

    (K,C,S) = x;
    C = min(K,C);
    if S < K-C+1: return "IMPOSSIBLE";

    offset = 0;
    for i in xrange(C-1): offset += i*K**(C-i);
    offsets = [ offset + i + 1 for i in xrange(C-1,K) ];
    if len(offsets) == 0: offsets = [offset];
    return " ".join(map(str,offsets));

#============================================

from argparser import parse;
from time import time;

if __name__ == '__main__':
    #infile = "D-small-attempt0.in";
    infile = "D-large.in";
    outfile = "D.out";

    buf=readBuffer();
    start=time();
    with open(outfile,"wt") as f:
        res = map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
