#!/usr/bin/env python
import sys
import random
def solveD(setN,setK):
    Nscore = 0 
    while(len(setN)>0):
        if max(setN) > max(setK):
            setN.remove(max(setN))
            setK.remove(max(setK))
            Nscore += 1
        else:
            Nblock = setN.pop(0)
            Kblock = setK.pop(-1)
            

    return Nscore

def solveW(setN,setK):
    Nscore = 0
    while(len(setN)>0):
        Nblock = setN.pop(0)
        if Nblock > setK[-1]:
            Kblock = setK.pop(0)
        else:
            i=len(setK)-1
            while (i>0) and (setK[i-1]>Nblock):
                i-=1
            Kblock = setK.pop(i)
        if Nblock>Kblock:
            Nscore += 1
    return Nscore

numcase = int(sys.stdin.readline())
#numcase = 50
for casenum in range(1,numcase+1):
    
    numblock = int(sys.stdin.readline())
    setN = sorted(map(float,sys.stdin.readline().strip().split()))
    
    setK = sorted(map(float,sys.stdin.readline().strip().split()))
    """
    setN = []   
    while len(setN)<1000:
        a = random.random()
        if not a in setN:
            setN.append(a)
    setN = sorted(setN)
    setK = []   
    while len(setK)<1000:
        a = random.random()
        if not (a in setK and a in setN):
            setK.append(a)
    setK = sorted(setK)
    """
    print 'Case #' + repr(casenum)+': '+str(solveD(list(setN),list(setK)))+' '+str(solveW(setN,setK))

