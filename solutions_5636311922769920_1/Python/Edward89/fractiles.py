import copy
def dataParser(fileDir):
    inputfile = open(fileDir,'rU')
    nbrOfCases = int(inputfile.readline())
    cases = [None for i in range(nbrOfCases)]
    for i in range(nbrOfCases):
        nbrs = inputfile.readline().split()
        cases[i] = [int(nbrs[j]) for j in range(len(nbrs))]
    inputfile.close()
    return cases

def solveCase(K,C):
    if C==1:
        return range(1,K+1)
    elif C>=K:
        idx = 0
        for i in range(K):
            idx = idx*K+i
        return [idx+1]
    else:
        output = list()
        idxBase = 0
        while idxBase<K:
            idx = 0
            for i in range(idxBase,min(K,idxBase+C)):
                idx = idx*K+i
            output.append(idx+1)
            idxBase+=C
        return output

def generateTiles(K,C):
    output = list()
    for goldDigit in range(K):
        base = [0]*K
        base[goldDigit] = 1
        if C==1:
            output.append(base)
        else:
            current = copy.deepcopy(base)
            for i in range(C-1):
                newCurrent = [0]*(len(current)*K)
                for j in range(len(current)):
                    if current[j]>0:
                        newCurrent[K*j:K*(j+1)] = [1 for k in range(K)]
                    else:
                        newCurrent[K*j:K*(j+1)] = copy.deepcopy(base)
                current = newCurrent
            output.append(current)
    return output

def verify(K,C,solution):
    tiles = generateTiles(K,C)
    for oneTile in tiles:
        detected = False
        for i in solution:
            if oneTile[i-1]>0:
                detected = True
                break
        if not detected:
            print oneTile
            print solution
            assert False



cases = dataParser('test.txt')
outputFile = open('out.txt','w')
for i in range(len(cases)):
    outputFile.write('Case #' + str(i + 1) + ':')
    K = cases[i][0]
    C = cases[i][1]
    S = cases[i][2]
    solution = solveCase(K,C)
    #verify(K,C,solution)
    if len(solution)>S:
        outputFile.write(' IMPOSSIBLE\n')
    else:
        for i in solution:
            outputFile.write(' '+str(i))
        outputFile.write('\n')
outputFile.close()
