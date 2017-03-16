
#============================================

def readBuffer():
#    '''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """
5
0
1
2
11
1692""".split("\n");
    #'''
    buf = filter(len,buf);

    t = int(buf[0]); buf=buf[1:];
    
    buf2 = map(int,buf);
    return buf2;

def solveProblem((rnd,x)):
    ## Do actions

    #i = solveProblem.q.get();
    print rnd, x;
    
    res = "INSOMNIA";
    s = set();
    for i in xrange(1,10000):
        if len(s) == 10: res = (i-1)*x; break;
        s |= { c for c in str(i*x) };
        print "\t%s\t%s\t%s"%(i,i*x,sorted(s));

    i = 0;
    print "%d >> Done, %s left\n"%(rnd+1,i);
    sys.stdout.flush();
    return res;

#============================================

from argparser import parse, parse1;
from multiprocessing import Pool, Queue;
from time import time;
import sys;

if __name__ == '__main__':
    infile = "A-small-attempt0.in";
    #infile = "A-large.in";
    outfile = "A.out";

    buf=readBuffer();
    start=time();
    with open(outfile,"wt") as f:
        q = Queue();
        for i in xrange(len(buf)-1,-1,-1): q.put(i);

        #p = Pool(1, initQueue, [q]);
        res = map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
