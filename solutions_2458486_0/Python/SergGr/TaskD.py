import itertools
import time
import operator
#import collections
from collections import Counter

#inputFileName = "test.in"
#inputFileName = "D-small-attempt0.in"
#inputFileName = "D-small-attempt1.in"
#inputFileName = "D-small-attempt2.in"
inputFileName = "D-small-attempt3.in"
#inputFileName = "D-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def calcSingleTest(f):
    line = f.readline()
    K = int(line.split()[0])
    N = int(line.split()[1])
    initKeysList = map(int, f.readline().split())
    #print initKeysList
    #initKeys = dict(itertools.groupby(initKeysList))
    initKeys = Counter(initKeysList)
    keyAvailable = initKeys.copy()
    keyRequired = Counter()
    #print initKeysList
    #print initKeys
    allChests = []
    for y in xrange(N):
        line = f.readline()
        dataLine = map(int, line.split())
        chest = (y, dataLine[0], dataLine[2:])
        keyRequired += Counter([dataLine[0]])
        keyAvailable += Counter(dataLine[2:])
        allChests.append(chest)

    keyRequired =  Counter(sorted(keyRequired.elements()))
    keyAvailable =  Counter(sorted(keyAvailable.elements()))
    keyRequiredList = sorted(((k, v) for k, v in keyRequired.iteritems()))
    keyAvailableList = sorted(((k, v) for k, v in keyAvailable.iteritems()))
    print "Req = " + str(keyRequiredList)
    print "Avl = " + str(keyAvailableList)
    #good = reduce(operator.and_, map(lambda r,a: r is None or r<=a,keyRequiredList, keyAvailableList))
    good = True
    for k, v in keyRequired.iteritems():
        a = keyAvailable[k]
        if a < v:
            good = False
    if not good:
        print "Bad!!!"
        return "IMPOSSIBLE"
        #print "Dif = " + str(keyAvailable - keyRequired)


    #print allChests
    allChestsIndices = range(N)
    solved = dict()
    empty = tuple([])
    solved[empty] = ([], initKeys)
    lastSolved = None
    someSolved = True
    for size in xrange(1, N + 1):
#        if not someSolved:
#            return "IMPOSSIBLE"
        someSolved = False
        #print "Solved = " + str(solved)
        #print '--------------'
        for problem in itertools.combinations(allChestsIndices, size):
            lastSolved = None
            #print "Solved = " + str(solved)
            #print problem
            #list_problem = map(lambda pos: allChests[pos], list(problem))
            list_problem = list(problem)
            for pos in xrange(size, 0, -1):
                # good order!
                #(chestIndex, chestOpenKey, chestKeys) =  list_problem[pos - 1]
                (chestIndex, chestOpenKey, chestKeys) = allChests[list_problem[pos - 1]]
                subproblem = tuple(list_problem[:pos - 1] + list_problem[pos:])
                if(subproblem in solved):
                    (subpath, subkeys) = solved[subproblem]
                    if(chestOpenKey in subkeys):
                        newKeys = subkeys.copy()
                        openKeys = Counter(chestKeys)
                        newKeys += openKeys
                        newKeys -= Counter([chestOpenKey])
                        #print subkeys
                        #print openKeys
                        #print newKeys
                        newPath = list(subpath)
                        newPath.append(chestIndex)
                        lastSolved = (tuple(newPath), newKeys)
                        someSolved = True
                        #print lastSolved
                        solved[problem] = (tuple(newPath), newKeys)
                        break

    print "K = {0}, N = {1}, Solved size {2}".format(K, N, len(solved))
    if not lastSolved:
        return "IMPOSSIBLE"
    else:
        (path, keys) = lastSolved
        return ' '.join(map(lambda x: str(x + 1), path))

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            res = calcSingleTest(inpF)
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            print ' '
            outF.write('Case #{0}: {1}\n'.format(i, res))
            outF.flush()

print "Finished!!!! Total time = {0}".format((time.time() - startTime))