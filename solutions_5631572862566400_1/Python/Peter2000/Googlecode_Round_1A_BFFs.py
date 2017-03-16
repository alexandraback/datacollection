# -*- coding: utf-8 -*-
"""
Created on Tue Apr  5 11:53:03 2016

@author: pellowes
"""
import numpy as np
import sys
sys.setrecursionlimit(10000)
#format 1 digit, then 
#n digits
#then 
#several data lines (x) based on one of the n digits
def readThroughDataGeneric(filename):
    outputs = []
    f = open(filename,'r')
    lct=0
    for line in f.readlines():
        #print (line.strip())
        if lct==0:
            pass          
        else:
            if(len(line.strip().split(' ')) < 3):
                pass
            else:
                parts = line.strip().split(' ')
                n = len(parts)+1
                bffs = np.zeros(n,dtype=np.int)
                for i in range(1,n):
                    bffs[i] = int(parts[i-1])
                outputs.append(solve(n,bffs))
        lct+=1
    f.close()
    return outputs        

def solve(n,bffs):
    #only mutual bffs allow anything other than a 1-directional circle
    mutualpairs = []
    for i in range(1,n):
        #print(bffs)
        #print(i)
        if i < bffs[i] and bffs[bffs[i]] == i:
            mutualpairs.append(i)
            mutualpairs.append(bffs[i])
    #all mutual pairs can be included, plus one chain ending at either
    ending_lengths = {}
    for i in range(1,n):
        chainendlength = recurseBFFs(n,bffs,i,mutualpairs,0,set(),i)
        if chainendlength[1] in ending_lengths and ending_lengths[chainendlength[1]] >= chainendlength[0]:
            continue
        #print(chainendlength)
        ending_lengths[chainendlength[1]] = chainendlength[0]
    #add them up
    runsum = len(mutualpairs)
    for i in ending_lengths:
        if i == -1: #sentinel
            continue
        runsum+=ending_lengths[i]
    print(ending_lengths)
    #compare to full circle
    if -1 not in ending_lengths:
        return runsum
    else:
        return max(runsum,ending_lengths[-1]) 
    
def recurseBFFs(n,bffs,ind,mutualpairs,ct,covered,start):
    #return ending id, and length
    if ind in mutualpairs:
        return [ct, ind]
    if ind in covered:
        if ind == start:
            return [ct, -1]
        else:
            return [0,-1]
    else:
        covered.add(ind)
        return recurseBFFs(n,bffs,bffs[ind],mutualpairs,ct+1,covered,start)

infile_name = '/Users/pellowes/Downloads/C-small-attempt0(1).in'
infile_name = '/Users/pellowes/Downloads/C-large.in'
#infile_name = '/Users/pellowes/dummydata'
outputs = readThroughDataGeneric(infile_name)
#print(len(outputs))
outfile_name = '/Users/pellowes/Downloads/out.out'
f = open(outfile_name,'w')
for i in range(0,len(outputs)):
    if i > 0:
        f.write('\n')
    f.write("Case #"+str(i+1)+": "+str(outputs[i]))
f.close()