
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
        #w = [parse1(buf[i],"i") for i in xrange(n)]; buf=buf[n:];
    
        buf2.append([K, C, S]);
        pass;
    return buf2;


def solveProblemEasy(K,C,S):
    #This assumes K == S
    return range(1,K+1);

def solveProblem((rnd,x)):
    ## Do actions

    (K,C,S) = x;

    res = solveProblemEasy(K,C,S);
    res = " ".join(map(str,res));

    #print rnd, x;

    return res;

#============================================

from argparser import parse, parse1;
from multiprocessing import Pool, Queue;
from time import time;
import sys;

if __name__ == '__main__':
    infile = "D-small-attempt0.in";
    #infile = "D-large.in";
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
