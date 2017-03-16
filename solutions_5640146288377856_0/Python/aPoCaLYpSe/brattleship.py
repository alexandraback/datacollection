import sys, os, math, functools
inpath = sys.argv[1]

lmap = lambda func, *iterable: list(map(func, *iterable))

def parseCase(instrm):
    return lmap(int, instrm.readline().strip().split(" "))

@functools.lru_cache(maxsize=100000)
def solveRec(W, rest):
    if rest == 0:
        return W-1
    if rest >= W or rest < 0:
        print("rest {} W {}".format(rest, W))
        raise Exception
    if rest == 1:
        return W
    
    if rest < W-1:
        cost = W - 1 - rest
        return solveRec(rest+1, rest) + cost
    
    bestCost = W-1
    for i in range(W-1):
        #Put bomb at position i
        #it was hit
        hitCost =  solveRec(i+i, i) + W - 1 - i
        #it wasn't hit
        nohitCost = 1 + solveRec(W, W-2-i)
        cost = max(hitCost, nohitCost)
        if cost > bestCost:
            bestCost = cost
    return cost

def presolve(C, W):
    if W==C:
        return W
    if W > C:
        raise Exception
    if C <= (2*W - 1):
        return solveRec(W, C-W) + 1
    return presolve(C-W, W) + 1 
    
def solveCase(case):
    R, C, W = case
    score =  presolve(C, W)
    if score > C or score < W:
        print("C {} W {} score {} rest {}".format(C, W, score, rest))
        raise Exception
    return score


if __name__=="__main__":
    instrm = open(inpath, 'r')
    cases = int(instrm.readline().strip())
    for i in range(cases):
        case = parseCase(instrm)
        res = solveCase(case)
        print("Case #{}: {}".format(i+1, res))
    instrm.close()


