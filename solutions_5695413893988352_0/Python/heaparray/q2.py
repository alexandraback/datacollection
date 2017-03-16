import math
import fractions

inFilePath =  'C:\\Users\\Orr\\Desktop\\CodeJam\\1B\\B-small.in'
outFilePath = 'C:\\Users\\Orr\\Desktop\\CodeJam\\1B\\B-small.out'
seperator = ' '

def parseFile(inFileName):
    inFile = open(inFileName)
    T = parseNum(inFile.readline())
    ProblemArr = []
    for k in range(T):
        (C,J) = (inFile.readline()[:-1]).split(' ')
        ProblemArr.append(ProblemSet(C,J,k))
    inFile.close()
    return ProblemArr


class ProblemSet():
    def __init__(self,C,J,k):
        self.C = C
        self.J = J
        self.k = k

def solvePS(ps):
    J = ps.J
    C = ps.C
    knowLarge = 0
    clarge = 0
    if C[0] != '?' and J[0] != '?' and C[0] != J[0]:
        knowLarge = 1
        if C[0] < J[0]:
            clarge = 1
        else:
            clarge = 0
    for i in range(len(J)):
        if knowLarge == 0 and i == len(J) - 1:
            (C,J) = replaceUnknownLarge(C,J,i)
        elif knowLarge == 0 and i != len(J) - 1:
            if J[i+1] == C[i+1] or C[i+1] == '?' or J[i+1] == '?':
                (C,J) = replaceUnknownLarge(C,J,i)
            elif J[i+1] > C[i+1]:
                knowLarge = 1
                clarge = 0
                (C,J,clarge) = replaceCriticalDigit(C,J,clarge,i,ps.C,ps.J)
            elif J[i+1] < C[i+1]:
                knowLarge = 1
                clarge = 1
                (C,J,clarge) = replaceCriticalDigit(C,J,clarge,i,ps.C,ps.J)
        elif knowLarge == 1:
            (C,J) = replaceKnownLarge(C,J,clarge,i)
    return C + ' ' + J
            
                
def replaceUnknownLarge(C,J,i):
    if J[i] == '?' and C[i] == '?':
        J = J.replace('?','0',1)
        C = C.replace('?','0',1)
    elif J[i] == '?':
        J = J.replace('?',min(J[i],C[i]),1)
    elif  C[i] == '?':
        C = C.replace('?',min(J[i],C[i]),1)
    return (C,J)

def replaceKnownLarge(C,J,clarge,i):
    if J[i] == '?':
        J = J.replace('?','0' if clarge else '9',1)
    if C[i] == '?':
        C = C.replace('?','9' if clarge else '0',1)
    return (C,J)

def replaceCriticalDigit(C,J,clarge,i,originC,originJ):
    if abs(int(J[i+1]) - int(C[i+1])) > 5:
        if J[i] == '?' and C[i] == '?':
            C = C.replace('?','0' if clarge else '1',1)
            J = J.replace('?','1' if clarge else '0',1)
            clarg = 1-clarge
        elif C[i] == '?':
            if clarge == 1 and J[i] == '0':
                C = handleCarry(C,originC,i,0)
            elif clarge == 0 and J[i] == '9':
                C = handleCarry(C,originC,i,1)
            else:
                C = C.replace('?',str(int(J[i])-1) if clarge else str(int(J[i])+1),1)
        elif J[i] == '?':
            if clarge == 0 and C[i] == '0':
                J = handleCarry(C,originC,i,0)
            elif clarge == 1 and C[i] == '9':
                J = handleCarry(C,originC,i,1)
            else:
                J = J.replace('?',str(int(C[i])+1) if clarge else str(int(C[i])-1),1)
    else:
        if J[i] == '?' and C[i] == '?':
            C =  C.replace('?','0',1)
            J =  J.replace('?','0',1)
        else:
            if J[i] == '?':
                J = J.replace('?',min(J[i],C[i]),1)
            elif  C[i] == '?':
                C = C.replace('?',min(J[i],C[i]),1)
    return (C,J,clarge)

def handleCarry(s,origin,i,overflow):
    s = list(s)
    if overflow == 1:
        if i == 0 or s[i-1] != '?':
            s[i] = '9'
            return ''.join(s)
        while i > 0 and origin[i-1] == '?':
            if s[i] == '9':
                s[i] = '0'
                i -=1
            s[i] = str(int(s[i])+1)
        return ''.join(s)
    if overflow == 0:
        if i == 0 or s[i-1] != '?':
            s[i] = '0'
            return ''.join(s)
        while i > 0 and origin[i-1] == '?':
            if s[i] == '0':
                s[i] = '9'
                i -=1
            s[i] = str(int(s[i])-1)
        return ''.join(s)
        
    
   
def parseNum(line):
    return int(line)

def parseVec(line):
    vecValues = line.split(seperator)
    return [int(value) for value in vecValues]

def stringVec(line):
    vecValues = line.split(seperator)
    return 

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
