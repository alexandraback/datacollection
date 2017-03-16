
#============================================

def readBuffer():
    '''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """1
16 50
    """.split("\n");
    #'''

    t = int(buf[0]); buf=buf[1:];
    buf2 = [ map(int,buf[0].split()) ];
    return buf2;

def initQueue(q):
    solveProblem.q = q;

def solveProblem((rnd,(N,J))):
    ## Do actions

    print "%s\t%s"%(N,J);

    res = [];
    c=0;
    for n in xrange(1<<N-2):
        arr = [ str(int((n & (1<<i))>0)) for i in xrange(N-2) ];
        v = "1" + "".join(arr) + "1";
        mul = [ int(v,d) for d in xrange(2,11) ];
        if any(True == isprime(d) for d in mul): continue;
        
        #print v, mul;

        arr=[];
        for m in mul:
            for p in small_primes:
                if p**2 > m: break;
                if m % p > 0: continue;
                arr.append(p);
                break;
            else: break;
        if len(arr) < 9: continue;

        res.append("%s %s"%(v, " ".join(map(str,arr))));
        c += 1;
        if c >= J: break;

    res = "\n%s"%("\n".join(res));

    print "%d >> Done, %s left\n"%(rnd+1,i);
    sys.stdout.flush();
    return res;

#============================================

from argparser import parse, parse1;
from multiprocessing import Pool, Queue;
from itertools import combinations;
from globals import isprime, small_primes;
from time import time;
import sys;

if __name__ == '__main__':
    infile = "C-small-attempt0.in";
    #infile = "C-large.in";
    outfile = "C.out";

    buf=readBuffer();
    start=time();
    with open(outfile,"wt") as f:
        q = Queue();
        for i in xrange(len(buf)-1,-1,-1): q.put(i);

        res = map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
