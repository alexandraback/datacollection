
#============================================

def readBuffer():
    #'''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """2
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
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

def pickRS(arr,rs):
    #print "rs = %s"%rs;
    yield rs;
    total=sum(arr[x] for x in rs);
    for i in xrange(rs[-1]-1,-1,-1):
        if(total+arr[i] > sumto[i]): "%s+%s == Too high"%(rs,arr[i]); break;
        nrs = rs+[i];
        for x in pickRS(arr,nrs): yield x;

def sumTo(arr,li,diff,ls):
    if(diff==0): yield ls; return;
    #print "LS = %s, diff = %s"%(ls,diff)

    for i in xrange(li,-1,-1):
        if(diff > sumto[i]+arr[i]): break;
        if(diff < arr[i]): continue;

        #print "Picking %s"%arr[i];
        nls = ls+[i];
        ndiff = diff-arr[i];
        
        for x in sumTo(arr,i-1,ndiff,nls):
            yield x;
            return;

def solveProblem((rnd,(n,arr))):
    global sumto;
    ## Do actions
    print n, arr;

    sumto = [sum(x for x in arr[:i]) for i in xrange(n)];
    
    print "sumto = %s"%sumto;
    
    m1,m2 = [], [];
    for i in xrange(len(arr)):
        bs = sum(x for x in arr[0:i]);
        if(bs == arr[i]): m1=arr[:i]; m2=[arr[i]]; break;
        if(bs < arr[i]): continue;
        for x in pickRS(arr,[i]):
            diff = sum(arr[y] for y in x);
            #print x, diff, sumto[x[-1]];
            for y in sumTo(arr,x[-1]-1,diff,[]):
                m1 = [arr[j] for j in x];
                m2 = [arr[j] for j in y];
                print "x = %s (%d), y = %s (%d)"%(m1, sum(m1), m2, sum(m2));
                break;
            else: continue;
            break;
        else: continue;
        break;

    i = solveProblem.q.get();
    print "%d >> Done, %s left\n"%(rnd+1,i);
    sys.stdout.flush();
    return m1,m2;

#============================================

from argparser import parse;
from multiprocessing import Pool, Queue;
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

        p = Pool(1, initQueue, [q]);
        res = p.map(solveProblem,enumerate(buf));

        for rnd,(m1,m2) in enumerate(res):
            if(len(m1)==0): st="Case #%d: Impossible\n";
            else: st="Case #%d:\n%s\n%s\n"%(rnd+1," ".join(map(str,m1)), " ".join(map(str,m2)));
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
