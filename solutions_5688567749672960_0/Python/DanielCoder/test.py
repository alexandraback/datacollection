from fractions import gcd
from functools import reduce
cache = {0:0, 1:1, 2:2, 3:3, 4:4, 5:5, 6:6, 7:7, 8:8, 9:9}
def naiveSolution(case, justFlipped = False, maxDepth = -1, currDepth = 0):
    global cache

    return cache[case]
def buildTable(maxCase):
    tenth = maxCase // 10
    for i in range(maxCase):
        
        #print (i)
        if i in cache:
            continue
        strFlip = str(i)[::-1]
        flipped = int(strFlip)
        if flipped >= i or strFlip[0] == "0":
            cache[i] = cache[i-1] + 1
        else:
            cache[i] = min(cache[i-1]+1, 1+cache[flipped])
    
        
            
        
"""
    if case in cache:
        return cache[case]
    if maxDepth == -1 or maxDepth > case:
        maxDepth = case + 1
    #print (" " * currDepth + " case: ", case, "Flipped:", justFlipped,"curr", currDepth, "max:", maxDepth)

    if currDepth > maxDepth:
        return 999999999
    minusOne = case - 1
    flippedStr = str(case)[::-1]
    if(flippedStr[0] == "0" or justFlipped):
        minusSol = naiveSolution(minusOne, False, minusOne, currDepth+1)
        cache[case] = minusSol + 1
        return cache[case]
    flipped = int(flippedStr)

    minusSol = naiveSolution(minusOne, False, minusOne, currDepth+1)
    flipSol = naiveSolution(flipped, True, min(minusSol, minusOne), currDepth+1)
    m = min(minusSol, flipSol)
    cache[case] = m + 1

    if case in cache:
        return cache[case]
    if case == 0:
        return 1
    elif case == 1:
        return 1
    elif justFlipped:
        return 1 + naiveSolution(case - 1)

    
    opt1 = case - 1
    opt2 = int(str(case)[::-1])

    opt1Res = naiveSolution(opt1, False, maxDepth)
    if maxDepth == -1:
        maxDepth = opt1Res
    else:
        maxDepth = min(maxDepth, opt1Res)
    opt2Res = naiveSolution(opt2, True, maxDepth)

    cache[case] = min(opt1Res, opt2Res)
    return cache[case] + 1"""
def parseInput(text):
    cases = []
    lines = text.splitlines()
    for i, line in enumerate(lines):
        if i == 0 :
            continue
        
        

        cases.append(int(line))
    return cases

def getOutput(solved):
    lines = []
    for i, solvedCase in enumerate(solved):
        lines.append("Case #%d: %d" % (i + 1, solvedCase))
    return '\n'.join(lines)

def generateOutput(filename, outFile = None):
    cases = getCases(filename)
    solvedCases = [naiveSolution(case) for case in cases]
    output = getOutput(solvedCases)
    if outFile == None:
        outFile = filename[:-2] + "out"
    with open(outFile, "w") as h:
        h.write(output)

    
def getCases(filename):
    with open(filename) as h:
        data = h.read()
    return parseInput(data)


def saveC(save = None):
    global cache
    with open("cache.obj", "wb") as h:
        pickle.dump(save if save is not None else cache, h)
def loadC():
    with open("cache.obj", "rb") as h:
        cache = pickle.load(h)
    return cache
