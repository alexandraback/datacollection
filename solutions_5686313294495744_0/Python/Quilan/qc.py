
#============================================

curProblem = "C";
curAttempt = 2;
curType = "example";
#curType = "practice";
curType = "small";
#curType = "large";

exampleString = """
3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC""";

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
        n = int(buf[0]); buf = buf[1:];
        nbuf = [];
        for _ in xrange(n):
            nbuf.append(buf[0].split(" "));
            buf=buf[1:];
        outBuf.append(nbuf);
    return outBuf;

def solveProblem(rnd, G):
    ## Do actions
    
    xv = {};
    yv = {};
    for i in xrange(len(G)):
        x,y = G[i];
        if x not in xv.keys(): xv[x] = len(xv.keys());
        if y not in yv.keys(): yv[y] = len(yv.keys());
        G[i][0] = xv[x];
        G[i][1] = yv[y];
    
    x2y = {};
    y2x = {};
    for x,y in G:
        if x not in x2y.keys(): x2y[x]=[];
        if y not in y2x.keys(): y2x[y]=[];
        x2y[x].append(y);
        y2x[y].append(x);
        x2y[x] = sorted(x2y[x]);
        y2x[y] = sorted(y2x[y]);

    #print G;
    print x2y;
    print y2x;

    fake=0;
    found=set();
    for start in sorted(x2y.keys()):
        for midy in x2y[start]:
            for midx in y2x[midy]:
                if midx == start: continue;
                for end in x2y[midx]:
                    if end == midy: continue;
                    xs = tuple(sorted([start,midx]));
                    ys = tuple(sorted([midy,end]));
                    key = xs,ys;
                    if key in found: continue;
                    found.add(key);
                    print "\tConflict: %s -> %s -> %s -> %s"%(start,midy,midx,end);
                    fake += 1;

    return fake;

#============================================

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
