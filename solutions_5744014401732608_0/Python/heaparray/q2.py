import math
import fractions

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\1C\\B-small.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\1C\\B-small.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        (B,M) = parseVec(inFile.readline())
        ProblemArr.append(ProblemSet(B,M))
    inFile.close()
    return ProblemArr


class ProblemSet():
    def __init__(self,B,M):
        self.B = B
        self.M = M

def solvePS(ps):
    if ps.M > 2**(ps.B-2):
        return 'IMPOSSIBLE'
    elif ps.M == 2**(ps.B-2):
        return printGraph(fullGraph(ps.B))
    else:
        return printGraph(bitsGraph(bin(ps.M)[2:],ps.B))

def fullGraph(size):
    graph = [[] for i in range(size)]
    for i in range(size):
        graph[i] = ['1' if i<j else '0' for j in range(size)]
    return graph

def bitsGraph(bits,size):
    graph = fullGraph(size-1)
    firstVecBits = '0' + bits.zfill(size-2) + '0'
    firstVec = [c for c in firstVecBits]
    for i in range(size-1):
        graph[i] = ['0'] + graph[i]
    graph = [firstVec] + graph
    return graph
    

def printGraph(graph):
    rows = []
    for i in range(len(graph)):
        row = ''.join(graph[i])
        rows.append(row)
    return 'POSSIBLE\n' + '\n'.join(rows)
   
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
