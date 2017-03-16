

# -*- coding: utf-8 -*-

import math
import random               

CASES = [
         [2,2,2],
         [3,3,3],
         [4,4,4],
         [5,5,5],
         ### 
         [2,2,3],
         [3,3,2],
         [2,2,4],
         [4,4,2],
         [2,2,5],
         [5,5,2],
         [3,3,4],
         [4,4,3],
         [3,3,5],
         [5,5,3],
         [4,4,5],
         [5,5,4],
         
         [3,4,5],
         [2,4,5],
         [2,3,5],
         [2,3,4]
        ]

import copy
def jobRun(ks):
    ''' Fair and Square numbers in [start, end]
    '''
    N = 3
    M = 5
    K = 7
    
    matchDict = dict()
    for i in ks:
        if i in matchDict:
            matchDict.update({i: matchDict[i]+1})
        else:
            matchDict.update({i:1})
    
    global CASES
    CASES = [tuple(i) for i in CASES]
    rank = len(CASES)
    
    while True:
        tempCases = copy.deepcopy(CASES)
        end = rank-1
        for i in xrange(rank):
            pos = random.randint(0, end)
            case = tempCases.pop(pos)
            end -=1
            
            resDict = dict()
            for i in xrange(K):
                res = 1
                for item in case:
                    if random.randint(0,1)==1:
                        res *=item
                if res in resDict:
                    resDict.update({res: resDict[res] +1})
                else:
                    resDict.update({res:1})
                    
            if resDict == matchDict:
                return case
    

        

def getinput():
    file = r'C:\ewy\C-small-1-attempt0.in'
    return open(file, 'r')

def saveoutput(results):
    resFile = r'C:\ewy\C-small.out'
    with open(resFile, 'w') as f:
        f.writelines(results)



def main():

    f = getinput()
    with f:
        N = int(f.readline().strip())
        print 'N:', N
        [R, N, M, K]=f.readline().strip().split()
        R = int(R)
        N = int(N)
        M = int(M)
        K = int(K)
        assert(R ==100)
        assert(N==3)
        assert(M==5)
        assert(K==7)
        resLines = 'Case #1:\n'
        for case in range(1,R+1):
            Ks = [int(i) for i in f.readline().strip().split()]
            assert(len(Ks)==K)
            res = jobRun(Ks)
        
            resLine = ''.join([str(i) for i in res])
            print resLine
            resLines +=resLine + '\n'
            
    saveoutput(resLines)
