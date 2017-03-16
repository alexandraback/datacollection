import sys
import numpy as np

def InputParser(inputstrs):
    T = int(inputstrs[0])
    residue = inputstrs[1:]
    probrems = []
    for i in xrange(T):
        A, N = map(int, residue[0].split())
        nus = map(int, residue[1].split())
        nus.sort()        
        probrems.append((A, N, nus))
        residue = residue[2:]

    return probrems

def OverrideValueCount(A, val, tmpcount):
    if A > val:
        return A, tmpcount
    else:
        return OverrideValueCount(A+A-1, val, tmpcount+1)

def Judge(A, iarray, count):
    if A == 1:
        return iarray.__len__()           
    if iarray == []:
        return count
    tmpval = iarray[0]
    if tmpval < A:
        return Judge(A+tmpval, iarray[1:], count) # go ahead
    else:        
        orA, orC = OverrideValueCount(A, tmpval, 0)        
        return min(Judge(orA + tmpval, iarray[1:], count+orC), count + iarray.__len__())

        
def Solve(problem):
    return Judge(problem[0], problem[2], 0)

def OutputString(results):
    outputstrings = []
    for i, result in enumerate(results):
        ostr = 'Case #' + (i+1).__str__() + ': ' + result.__str__()
        outputstrings.append(ostr)

    return outputstrings

if __name__ == '__main__':
    inputfilename = sys.argv[1]      
    
    with open(inputfilename) as f:
        inputstrs = f.readlines()
    
    problems = InputParser(inputstrs)
    results = []
    for i, problem in enumerate(problems):        
        results.append(Solve(problem))
        
    for result in OutputString(results):
        print result