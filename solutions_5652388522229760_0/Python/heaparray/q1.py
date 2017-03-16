import math

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\A-small-practice.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\A-small-practice.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        currN = parseNum(inFile.readline())
        ProblemArr.append(ProblemSet(currN))
    inFile.close()
    return ProblemArr



class ProblemSet():
    def __init__(self,N):
        self.N = N
        

def solvePS(ps):
    N = ps.N
    currNum = N
    if N == 0:
        return 'INSOMNIA'
    else:
        digits = {}
        while True:
            for c in str(currNum):
                digits[c] = 1
            if len(digits) == 10:
                return currNum
            currNum += N
            
        
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
