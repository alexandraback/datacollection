
#============================================

curProblem = "B";
curAttempt = 3;
curType = "example";
#curType = "practice";
curType = "small";
#curType = "large";

exampleString = """
1
46? ???""";

def getInput():
    if curType == "example": return exampleString;

    fileName = "%s-"%(curProblem);
    if curType == "large": fileName = "%s-large.in"%(curProblem);
    if curType == "small": fileName = "%s-small-attempt%d.in"%(curProblem,curAttempt);
    if curType == "practice": fileName = "%s-small-practice.in"%(curProblem);

    with open(fileName, "rt") as f:
        buf = f.readlines();

    return "".join(buf);

def parseInput(buf):
    buf = buf.split("\n");
    buf = filter(len,buf);

    t = int(buf[0]); buf=buf[1:];
    outBuf = [];
    for _ in xrange(1,t+1):
        #n, = parse(buf[0],"i"); buf=buf[1:];
        #w = [parse1(buf[i],"i") for i in xrange(n)]; buf=buf[n:];

        #outBuf.append([n, w]);
        outBuf.append( buf[0].split(" ") );
        buf = buf[1:];
        pass;
    return outBuf;

def combinations_with_replacement(iterable, r):
    pool = tuple(iterable)
    n = len(pool)
    for indices in product(range(n), repeat=r):
        if sorted(indices) == list(indices):
            yield tuple(pool[i] for i in indices)

def solveProblem(rnd, (t1,t2)):
    ## Do actions
    
    rep1 = [];
    for i,v in enumerate(t1):
        if v == "?": rep1.append(i);
    rep2 = [];
    for i,v in enumerate(t2):
        if v == "?": rep2.append(i);

    best = (1000000, 1000000, 1000000, 0, 0);
#     for r1 in combinations_with_replacement("0123456789", len(rep1)):
#         for r2 in combinations_with_replacement("0123456789", len(rep2)):
    fmt1 = "%%0%dd"%(len(rep1));
    fmt2 = "%%0%dd"%(len(rep2));
    #print fmt1, fmt2;
    #exit(0);
    for r1 in xrange(10**len(rep1)):
        r1 = fmt1%r1;
        for r2 in xrange(10**len(rep2)):
            r2 = fmt2%r2;
            n1 = list(t1);
            n2 = list(t2);
            for r,ind in zip(r1,rep1): n1[ind] = r;
            for r,ind in zip(r2,rep2): n2[ind] = r;
            
            #print "".join(n1), "".join(n2);
            on1 = "".join(n1);
            on2 = "".join(n2);
            n1,n2 = int(on1), int(on2);
            diff = abs(n1 - n2);
            #print "n1 = %s, n2 = %s, diff = %s, best = %s"%(n1,n2,diff, best);
            pair = (diff, n1, n2, on1, on2);
            best = min(best, pair);

    print rnd, t1, t2, best;
    #exit(0);

    n1, n2 = best[3:];

    return "%s %s"%(n1, n2);

#============================================

from itertools import product;
from time import time;

if __name__ == '__main__':
    inputData = parseInput(getInput());
    outfile = "%s.out"%(curProblem);

    start=time();
    with open(outfile,"wt") as f:
        for rnd, inp in enumerate(inputData):
            res = solveProblem(rnd, inp);
            st="Case #%d: %s\n"%(rnd+1,res);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
