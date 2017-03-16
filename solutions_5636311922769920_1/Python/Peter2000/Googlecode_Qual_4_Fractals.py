# -*- coding: utf-8 -*-
"""
Created on Tue Apr  5 11:53:03 2016

@author: pellowes
"""
import numpy as np
#format 1 digit, then 
#n digits
#then 
#several data lines (x) based on one of the n digits
def readThroughDataGeneric(filename):
    outputs = []
    f = open(filename,'r')
    lct=0
    for line in f.readlines():
        if lct==0:
            t = int(line.strip())          
        else:
            #run the solver
            l = line.strip().split(' ')
            k = int(l[0])
            c = int(l[1])
            s = int(l[2])
            
            #outputs.append(findPossibleLead(k,c))
            outputs.append(coverQuickly(k,c,s))
        lct+=1
    f.close()
    return outputs        
        
#N*K^(C-1)+N
def findPossibleLead(k,c):
    ppbs = []    
    for n in range(0,k):
        runsum = 0
        tempc = c
        while tempc >=1:
            runsum+=n*k**(tempc-1)
            tempc-=1
        ppbs.append(runsum+1)
        #ppbs.append(n*(k**(c-1))+n+1)
    return ppbs
    
def coverQuickly(k,c,s):
    paus = []
    curr_ind = 0 #position we are checking
    p = 0#pass we are on
    while curr_ind < k:
        runsum = 0
        tempc = c
        while tempc >=1:
            ind = min(k-1,curr_ind)            
            runsum+=ind*(k**(tempc-1))
            tempc-=1
            curr_ind+=1
            print(runsum)
        paus.append(runsum+1)
        print('---')
        p+=1
    print('-----')
    if len(paus) <= s:
        return paus
    else:
        return ["IMPOSSIBLE"]
        
    


#infile_name = '/Users/pellowes/Downloads/D-small-attempt0.in'
infile_name = '/Users/pellowes/Downloads/D-large.in'
#infile_name = '/Users/pellowes/dummydata'
outputs = readThroughDataGeneric(infile_name)
print(len(outputs))
outfile_name = '/Users/pellowes/Downloads/out2.out'
f = open(outfile_name,'w')
for i in range(0,len(outputs)):
    if i > 0:
        f.write('\n')
    f.write("Case #"+str(i+1)+":")
    for j in range(0,len(outputs[i])):
        f.write(" " +str((outputs[i][j])))
f.close()