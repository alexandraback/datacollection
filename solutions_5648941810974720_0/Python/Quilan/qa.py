
#============================================

curProblem = "A";
curAttempt = 0;
curType = "example";
#curType = "practice";
curType = "small";
#curType = "large";

exampleString = """
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER""";

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
        outBuf.append(buf[0]);
        buf=buf[1:]
        pass;
    return outBuf;

def solveProblem(rnd, word):
    ## Do actions
    
    let = { 0 : "ZERO", 1 : "ONE", 2 : "TWO", 3 : "THREE", 4 : "FOUR", 5 : "FIVE", 6 : "SIX", 7 : "SEVEN", 8 : "EIGHT", 9 : "NINE" }
    l2n = {}
    
    uniq = {"G" : 8, "U" : 4, "W" : 2, "X" : 6, "Z" : 0}
    uniq2 = { "F" : 5, "H" : 3, "O" : 1, "S" : 7}
    
    for n,v in let.items():
        for x in v:
            if x not in l2n.keys(): l2n[x]=[];
            l2n[x].append(n);

#     for x,nd in l2n.items():
#         print x, nd;
    
    lcount = {};
    for l in word:
        if l not in lcount.keys(): lcount[l]=0;
        lcount[l] += 1;
    
    numbers={};
    for uk,n in uniq.items():
        if uk not in lcount.keys(): continue;
        ct = lcount[uk]
        numbers[n] = ct;
        for l in let[n]:
            lcount[l] -= ct;
            if lcount[l] == 0: del lcount[l];

    for uk,n in uniq2.items():
        if uk not in lcount.keys(): continue;
        ct = lcount[uk]
        numbers[n] = ct;
        for l in let[n]:
            lcount[l] -= ct;
            if lcount[l] == 0: del lcount[l];

    if "I" in lcount.keys():
        numbers[9] = lcount["I"];

    st = "";
    for n,c in sorted(numbers.items()):
        st = "%s%s"%(st, ("%s"%n)*c);

    print "Word: %s, nums: %s, counts: %s"%(word, numbers, lcount);

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
