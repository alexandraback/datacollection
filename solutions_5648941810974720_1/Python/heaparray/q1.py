import math
import fractions

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\1B\\A-large.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\1B\\A-large.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        string = inFile.readline()[:-1]
        ProblemArr.append(ProblemSet(string))
    inFile.close()
    return ProblemArr


class ProblemSet():
    def __init__(self,string):
        self.string = string

def solvePS(ps):
    d = {}
    for c in ps.string:
        if d.get(c) == None:
            d[c] = 0
        d[c] +=1

    a6 = reduceletters(d,'X','SIX',6)
    a0 = reduceletters(d,'Z','ZERO',0)
    a8 = reduceletters(d,'G','EIGHT',8)
    a2 = reduceletters(d,'W','TWO',2)
    a4 = reduceletters(d,'U','FOUR',4)
    a3 = reduceletters(d,'H','THREE',3)
    a1 = reduceletters(d,'O','ONE',1)
    a5 = reduceletters(d,'F','FIVE',5)
    a7 = reduceletters(d,'S','SEVEN',7)
    a9 = reduceletters(d,'N','NINE',9)
    return ''.join(a0+a1+a2+a3+a4+a5+a6+a7+a8+a9)

def reduceletters(d,distinct,reduce,retNum):
    retArr = []
    while d.get(distinct,0) > 0:
        for c in reduce:
            d[c] -= 1
            assert(d[c] > -1)
        retArr.append(str(retNum))
    return retArr
    
    
   
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
#ps = ProblemSet([24,97,2])
#print(solvePS(ps))
