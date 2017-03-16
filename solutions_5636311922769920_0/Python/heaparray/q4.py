import math
import random

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\D-small.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\D-small.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        (K,C,S) = parseVec(inFile.readline())
        ProblemArr.append(ProblemSet(K,C,S))
    inFile.close()
    return ProblemArr


class ProblemSet():
    def __init__(self,K,C,S):
        self.K = K
        self.C = C
        self.S = S

def solvePS(ps):
    if ps.S * ps.C < ps.K:
        return 'IMPOSSIBLE'
    else:
        studentList = []
        indexesCheckes = [i for i in range(ps.K)]
        while len(indexesCheckes) > 0:
            currIndexes = indexesCheckes[:ps.C]
            indexesCheckes = indexesCheckes[ps.C:]
            currLocation = 1
            for i in range(len(currIndexes)):
                currLocation += (ps.K**i)*currIndexes[i]
            studentList.append(str(currLocation))
        return ' '.join(studentList)
        
        
def parseNum(line):
    return int(line)

def parseVec(line):
    vecValues = line.split(seperator)
    return [int(value) for value in vecValues]

def psOutFormat(iterNum,res):
    return 'Case #{0}: {1}\n'.format(iterNum+1,res)
        
def writeToFile(results,outFileStr):
    outFile = open(outFileStr,'w')
    try:
        resultArr = [psOutFormat(i,results[i]) for i in range(len(results))]
        outFile.writelines(resultArr)
    finally:
        outFile.close()
    
def solveProblemSet():
    ps = parseFile(inFilePath)
    results = []
    for i in range(len(ps)):
        results.append(solvePS(ps[i]))
    writeToFile(results,outFilePath)
    print('done!')


solveProblemSet()
#ps = ProblemSet(1211)
#print(solvePS(ps))
