import math

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\B-small.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\B-small.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        currStr = inFile.readline()[:-1]
        ProblemArr.append(ProblemSet(currStr))
    inFile.close()
    return ProblemArr



class ProblemSet():
    def __init__(self,s):
        self.s = s
        

def solvePS(ps):
    panStr = ps.s
    panStr = panStr.replace('-','0')
    panStr = panStr.replace('+','1')
    flipCount = 0
    while panStr.rfind('0') != -1:
        panStr = flip(panStr,panStr.rfind('0'))
        flipCount += 1
    return flipCount

def flip(string,digitNum):
    newStr = []
    for i in range(digitNum+1):
        if(string[i] == '0'):
            newStr.append('1')
        else:
            newStr.append('0')
    return ''.join(newStr)+string[digitNum+1:]
    
        
        
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
