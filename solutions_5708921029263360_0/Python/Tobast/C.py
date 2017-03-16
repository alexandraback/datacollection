from copy import copy

def solve():
    inp = [int(x) for x in input().split() ]
    poss = inp[:3]
    maxPairs = inp[3]
    pairsUsed = [ [ [maxPairs] * (poss[2]+1) for i in range(poss[1]+1) ]\
                    for j in range(poss[0]+1) ]
    def canWear(assem, appl=False):
        def check(a):
            return pairsUsed[a[0]][a[1]][a[2]] > 0
        def doAppl(a):
            pairsUsed[a[0]][a[1]][a[2]] -= 1
        s1,s2,s3 = copy(assem), copy(assem), copy(assem)
        s1[0] = -1
        s2[1] = -1
        s3[2] = -1
        can = check(s1) and check(s2) and check(s3)
        if not appl:
            return can
        if can:
            doAppl(s1)
            doAppl(s2)
            doAppl(s3)
        return can
        
    outf = []
    def dumpOutf(x):
        return "{} {} {}".format(x[0]+1,x[1]+1,x[2]+1)
    def explore(cur):
        if not canWear(cur):
            return 0
        if cur[2] >= 0:
            canWear(cur, True)
            outf.append(dumpOutf(cur))
            return 1
        for state in range(3):
            if cur[state] < 0:
                out = 0
                for i in range(poss[state]):
                    cur[state] = i
                    out += explore(cur)
                cur[state] = -1
                return out
    explore([-1,-1,-1])
    out = "{}\n".format(len(outf))
    for of in outf:
        out += of+'\n'
    return out[:-1]

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1,solve()))
