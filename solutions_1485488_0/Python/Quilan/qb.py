
#============================================

def readBuffer():
    #'''
    with open(infile,"rt") as f: buf = f.readlines();
    buf=map(lambda x: x[:-1], buf);
    '''
    buf = """4
200 1 2
250 233
180 100
100 3 3
500 500 500
500 500 600
500 140 1000
10 10 10
10 10 490
10 10 10
100 3 3
500 100 500
100 100 500
500 500 500
10 10 10
10 10 10
10 10 10
100 2 2
1000 1000
1000 1000
100 900
900 100
    """.split("\n");
    #'''

    t = int(buf[0]); buf=buf[1:];
    buf2 = [];
    for _ in xrange(1,t+1):
        h,n,m = parse(buf[0],"iii"); buf=buf[1:];
        c = [parse("%d %s"%(m,buf[i]),"iI0")[1] for i in xrange(n)]; buf=buf[n:];
        f = [parse("%d %s"%(m,buf[i]),"iI0")[1] for i in xrange(n)]; buf=buf[n:];

        buf2.append([h, n, m, c, f]);
        pass;
    return buf2;

def initQueue(q):
    solveProblem.q = q;

def neighbors((n,m),(c,f),(i,j)):
    for (y,x) in [[0,-1],[-1,0],[1,0],[0,1]]:
        if(i+y>=n or i+y<0): continue;
        if(j+x>=m or j+x<0): continue;
        
        if(f[i][j] > c[i+y][j+x]-50): continue;
        if(c[i][j] < f[i+y][j+x]+50): continue;
        if(c[i+y][j+x]-f[i+y][j+x] < 50): continue;
        yield (i+y,j+x);
    
def roomHeight(c,f,i,j,cw): return c[i][j]-max(cw,f[i][j]);
    
def solveProblem((rnd,(h,n,m,c,f))):
    ## Do actions

    mt={ (0,0) : 100000 };
    mv={ (0,0) : (0,-1,-1)};
    cv={ (0,0,0) : (-1,-1) };
    while len(cv.keys())>0:
        ncv={};
        for (i,j,t),fr in cv.items():
            if( (i,j) in mt and mt[i,j] <= t): print "Already been to %s,%s"%(i,j); continue;
            mt[i,j]=t;
            mv[i,j]=fr;
            if(i == n-1 and j == m-1): continue;
            print "Visiting %s,%s at %s"%(i,j,t);
            
            cw = max(0,h-10*t);
            print "Cur water height = %s"%(cw);
            for (ni,nj) in neighbors((n,m),(c,f),(i,j)):
                rh = roomHeight(c,f,ni,nj,cw);              #current dest room height
                ttw = max(0,(50.0-rh)/10);                  #time req to wait
                nw = cw-10*ttw;                             #new height after waiting
                crw = max(0,nw-f[i][j]);                    #cur room water height after waiting
                
                if(crw >= 20):
                    if(t == 0 and ttw==0):
                        print "Instant Swimming to %s,%s"%(ni,nj)
                        ncv[ni,nj,0] = (i,j);
                    else:
                        print "Swimming to %s,%s"%(ni,nj)
                        ncv[ni,nj,t+ttw+1] = (i,j);
                else:
                    if(t == 0 and ttw==0):
                        print "Instant Draggin to %s,%s"%(ni,nj);
                        ncv[ni,nj,0] = (i,j);
                    else:
                        print "Draggin to %s,%s"%(ni,nj);
                        ncv[ni,nj,t+ttw+10] = (i,j);

                pass;
        cv=ncv;

    print "Time taken to get to: %s"%(mt[n-1,m-1]);
    i = solveProblem.q.get();
    print "%d >> Done, %s left\n"%(rnd+1,i);
    sys.stdout.flush();
    return mt[n-1,m-1];

#============================================

from argparser import parse;
from multiprocessing import Pool, Queue;
from time import time;
import sys;

if __name__ == '__main__':
    infile = "B-small-attempt0.in";
    #infile = "B-large.in";
    outfile = "B.out";

    buf=readBuffer();
    start=time();
    with open(outfile,"wt") as f:
        q = Queue();
        for i in xrange(len(buf)-1,-1,-1): q.put(i);

        p = Pool(1, initQueue, [q]);
        res = p.map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %f\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
