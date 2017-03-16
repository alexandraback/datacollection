
#============================================

curProblem = "B";
curAttempt = 0;
curType = "example";
#curType = "practice";
#curType = "small";
curType = "large";

exampleString = """
1
50 3000
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

def solveProblem(B,M):
    global cdb;

    print "B=%s,M=%s"%(B,M);

    if M > (1<<(B-2)):
        return "IMPOSSIBLE";
    if M < 1:
        return "IMPOSSIBLE";

    G = [ [0]*B ];
    for ind in xrange(1,B):
        rem = M - (1<<(ind-1));
        #print "\tRem: %s\t%s"%(rem, (1<<(ind-1)));
        if rem >= 0:
            nRow = [0]*(B-ind) + [1]*(ind);
            #print "\tAdding row %s"%(nRow);
            G.append( nRow );
            continue;

        nRow = 1<<(ind-1);

        nrem = M - (1<<(ind-2));
        if nrem <= 0:
            nRow = [ int(nRow & (1<<i) > 0) for i in xrange(B) ];
            nRow = list(reversed(nRow));
            G.append( nRow );
            #print "\tDefaulting row %s"%(nRow);
            continue;

        nRow |= 2*nrem - 1;
        nRow = [ int(nRow & (1<<i) > 0) for i in xrange(B) ];
        nRow = list(reversed(nRow));
        G.append(nRow);
        #print "\tAdding partial row %s"%(nRow);

        #if M 1<<ind > M: break;

    G = list(reversed(G));
    
    cdb={};
    numWays = countWays(0,G);
    if numWays != M:
        print "ERROR: Differing number of ways!!";
        exit(0);
    
    st = "POSSIBLE";
    for v in G:
        st = "%s\n%s"%(st, "".join(map(str,v)));

    return st;

#============================================

from time import time;

if __name__ == '__main__':
    inputData = parseInput(getInput());
    outfile = "%s.out"%(curProblem);

    start=time();
    with open(outfile,"wt") as f:
        for rnd, inp in enumerate(inputData):
            res = solveProblem(inp[0],inp[1]);
            st="Case #%d: %s\n"%(rnd+1,res);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
