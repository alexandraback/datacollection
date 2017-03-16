import sys
import numpy as np

def InputParser(inputstrs):
    T = int(inputstrs[0])
    residue = inputstrs[1:]
    probrems = []
    for i in xrange(T):
        probrems.append(map(int, residue[0].split()))
        residue = residue[1:]

    return probrems


def CalcArea(startr, n):
    return 2*n*(n-1) + (2*startr + 1)*n


def Search(paint, startr, tmpn, min, max, trial):    
    ima = CalcArea(startr, tmpn) 
    tugi = CalcArea(startr, tmpn+1)
    if ima <= paint and tugi > paint:        
        return tmpn
    else:        
        if ima <= paint:           
            return Search(paint, startr, tmpn + (max - tmpn)/2, tmpn, max, trial+1)
        else:            
            return Search(paint, startr, min + (tmpn - min)/2, min, tmpn, trial+1)

def Solve(inputpair):
    r = inputpair[0]
    t = inputpair[1]
    return Search(t, r, 1, 1, int(np.sqrt(t) + 1),0)


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
    
    probrems = InputParser(inputstrs)
    results = map(Solve, probrems)
        
    for result in OutputString(results):
        print result