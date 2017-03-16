import math
import random

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\C-small.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\qualifications\\C-small.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        (N,J) = parseVec(inFile.readline())
        ProblemArr.append(ProblemSet(N,J))
    inFile.close()
    return ProblemArr

def miller_rabin_pass(a, s, d, n):
    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in range(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1


def miller_rabin(n):
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
	
    for repeat in range(22):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not miller_rabin_pass(a, s, d, n):
            return False
    return True


def getDivisors(n):
    if miller_rabin(n) == True:
        return -1
    for i in range(2,min(math.ceil(math.sqrt(n))+1,15000)):
        if n % i == 0:
            return i
    return -1

class ProblemSet():
    def __init__(self,N,J):
        self.N = N
        self.J = J

def solvePS(ps):
    #choose randomly until hit good number
    codeJams = {}
    while len(codeJams) < ps.J:
        s = random.getrandbits(ps.N-2)*2 + 1 + 2**(ps.N-1)
        s = bin(s)[2:]
        if(codeJams.get(s) == True):
            continue
        sdiv = []
        assert(len(s) == ps.N)
        for i in range(2,11):
            d = getDivisors(int(s,i))
            if d == -1:
                break
            else:
                sdiv.append(str(d))
        if len(sdiv) == 9:
           codeJams[s] = sdiv
    lineArr = [key+ ' ' + ' '.join(codeJams[key]) for key in codeJams.keys()]
    return '\n'+ '\n'.join(lineArr)
        
    
        
        
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
