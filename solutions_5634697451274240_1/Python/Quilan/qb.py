
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

def iterMethod(S,arr):
    def flip(arr,ind): return [ 1-x for x in reversed(arr[:ind]) ] + arr[ind:];

    if all(x == 0 for x in arr): return 0;
    turns = 0;

    last1 = S;

    while True:
        if all(x == 0 for x in arr): return turns;
        turns += 1;

        while last1 > 0 and arr[last1-1]==0: last1-=1;

        #the easy case -- we can flip right now!
        if arr[0] == 1: arr = flip(arr,last1); continue;

        #the harder case -- we must find the next 0, and flip from there
        next0 = last1;
        while next0 > 0 and arr[next0-1]==1: next0-=1;
        arr = flip(arr,next0);
        continue;

def solveProblem((rnd,x)):
    S = len(x);
    x = map(lambda z: 1 if z=="-" else 0, x);
    print rnd, (S,x);

    return iterMethod(S,x);

#============================================

from time import time;

if __name__ == '__main__':
    #infile = "B-small-attempt0.in";
    infile = "B-large.in";
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
