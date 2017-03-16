
#============================================

curProblem = "B";
curAttempt = 0;
curType = "example";
#curType = "practice";
curType = "small";
#curType = "large";

exampleString = """
3
6 15
2 1
4 20
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
        b,m = map(int, buf[0].split()); buf=buf[1:];

        outBuf.append([b, m]);
        pass;
    return outBuf;

cdb={};
def countWays(ind,G):
    B = len(G);
    if ind == B-1: return 1;
    
    try: return cdb[ind];
    except: pass;

    total = 0;
    for i,v in enumerate(G[ind]):
        if v == 0: continue;
        total += countWays(i,G);

    cdb[ind] = total;
    return total;

def rec(ind,avail,B,st=[]):
    #print "ind=%s, avail=%s, st=%s, mx=%s"%(ind,avail,st,(1<<(B-1-ind))-1);

    if ind == B-1:
        yield st;
        return;

    if ind not in avail:
        return;

    navail = min(ind + 1, B-1);
    for n in xrange(1, (1<<(B-ind))):
        arr = [ int(n & (1<<(B-i-1)) > 0) for i in xrange(B) ];
        if arr[ind] == 1: continue;
        if arr[navail] == 0: continue;

        nxAvail = set();
        for i in xrange(len(arr)):
            if arr[i] == 1: nxAvail.add(i);
        nxAvail |= avail;
        nxAvail = { v for v in nxAvail if v > ind };

        for g in rec(ind+1,nxAvail,B,st+[arr]):
            yield g;

def solveProblem(rnd, (B,M)):
    ## Do actions
    global cdb;

    for G in rec(0,{0},B):
        G.append([0]*B);
        cdb={};
        numWays = countWays(0,G);
        #print "%s\t%s"%(G, numWays);

        if numWays != M:
            continue;

        st = "POSSIBLE";
        for v in G:
            st = "%s\n%s"%(st, "".join(map(str,v)));

        return st;

    return "IMPOSSIBLE";

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
