
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
    if x == 0: return "INSOMNIA";
    s = set();
    i=0;
    while True:
        i += 1;
        if len(s) == 10: res = (i-1)*x; break;
        s |= { c for c in str(i*x) };

    return res;

#============================================

from time import time;

if __name__ == '__main__':
    #infile = "A-small-attempt0.in";
    infile = "A-large.in";
    outfile = "A.out";

    buf=readBuffer();

    start=time();
    with open(outfile,"wt") as f:
        res = map(solveProblem,enumerate(buf));

        for rnd,r in enumerate(res):
            st="Case #%d: %s\n"%(rnd+1,r);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
