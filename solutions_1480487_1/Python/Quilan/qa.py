
#============================================

def readBuffer():
    #'''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21
    """.split("\n");
    #'''

    t = int(buf[0]); buf=buf[1:];
    buf2 = [];
    for _ in xrange(1,t+1):
        n,arr = parse(buf[0],"iI0"); buf=buf[1:];
    
        buf2.append([n, arr]);
        pass;
    return buf2;

def initQueue(q):
    solveProblem.q = q;

def solveProblem((rnd,(n,arr))):
    ## Do actions
    
    print "arr = %s"%arr;
    y = 1.0*sum(arr);
    i=0;
    l=0.0;
    h=1.0;

    for _ in xrange(100):
        m=(l+h)/2.0;
        v = arr[i]+y*m;

        mva = [m]+[max((v-x)/y,0.0) for j,x in enumerate(arr) if i!=j];
        t=1-sum(mva);
        
        if(t<0): h=m;
        else: l=m;

    mva = mva;
    print "m = %s, mva = %s"%(m,mva);

    i = solveProblem.q.get();
    print "%d >> Done, %s left\n"%(rnd+1,i);
    sys.stdout.flush();
    return mva;

#============================================

from argparser import parse;
from multiprocessing import Pool, Queue;
from time import time;
import sys;

if __name__ == '__main__':
    infile = "A-small-attempt2.in";
    infile = "A-large.in";
    outfile = "A.out";

    buf=readBuffer();
    start=time();
    with open(outfile,"wt") as f:
        q = Queue();
        for i in xrange(len(buf)-1,-1,-1): q.put(i);

        p = Pool(1, initQueue, [q]);
        res = p.map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1," ".join(map(lambda x: "%f"%(100.0*x),r)));
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
