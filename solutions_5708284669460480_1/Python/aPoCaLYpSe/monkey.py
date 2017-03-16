import sys, os, math
inpath = sys.argv[1]

lmap = lambda func, *iterable: list(map(func, *iterable))

def parseCase(instrm):
    args = lmap(int, instrm.readline().strip().split(" "))
    S = args[2]
    alpha = instrm.readline().strip()
    target = instrm.readline().strip()
    return (S, alpha, target)

def solveCase(case):
    S, alpha, target = case
    L = len(target)
    K = len(alpha)
    keys = {}
    for k in target:
        keys[k] = 0
    keys["@"] = 0
    for a in alpha:
        if a in target:
            keys[a] += 1
        else:
            keys["@"] += 1
    #check that it is feasible
    for k in target:
        if keys[k]==0:
            return 0
    #compute probabilities
    for k in keys:
        keys[k] = keys[k]/float(K)
    #compute probability of the target
    tprob = 1
    for k in target:
        tprob *= keys[k]
    #expected occurrences
    exp = tprob*(S-L+1)
    #maximum num of occurrences
    minshift = L
    for s in range(1, L):
        if target[s:] == target[:-s]:
            minshift = s
            break
    maxocc = math.floor(((S-(L-minshift))/float(minshift)))
    return maxocc - exp

if __name__=="__main__":
    instrm = open(inpath, 'r')
    cases = int(instrm.readline().strip())
    for i in range(cases):
        case = parseCase(instrm)
        res = solveCase(case)
        print("Case #{}: {}".format(i+1, res))
    instrm.close()


