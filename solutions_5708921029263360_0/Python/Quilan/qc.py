
#============================================

curProblem = "C";
curAttempt = 0;
curType = "example";
#curType = "practice";
curType = "small";
#curType = "large";

exampleString = """
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
""";

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
        J,P,S,K = map(int,buf[0].split()); buf=buf[1:];

        outBuf.append([J,P,S,K]);
        pass;
    return outBuf;

def solveProblem(rnd, (J,P,S,K)):
    ## Do actions

    arr = [];
    db1={};
    db2={};
    db3={};
    for j in xrange(J):
        for p in xrange(P):
            for s in xrange(S):
                key = (j,p,s);
                k1 = (j,p);
                k2 = (j,s);
                k3 = (p,s);
                if k1 not in db1: db1[k1]=0;
                if k2 not in db2: db2[k2]=0;
                if k3 not in db3: db3[k3]=0;
                
                if db1[k1] >= K: continue;
                if db2[k2] >= K: continue;
                if db3[k3] >= K: continue;
                
                db1[k1] += 1;
                db2[k2] += 1;
                db3[k3] += 1;
                arr.append(key);

    st = "%s"%(len(arr));
    for v in arr:
        st = "%s\n%s"%(st, " ".join([ str(x+1) for x in v ]));

    return st;

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
