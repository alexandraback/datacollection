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
    ct=0
    ctlast = 0
    rcs = []
    for line in f.readlines():
        #print (line.strip())
        if lct==0:
            pass  
        elif ct==0:
            #get new ct
            ct = int(line.strip())*2-1
            if(lct > 1):
                sln = solve(rcs)
                outputs.append(sln)
                if len(sln) != ctlast:
                    print(sln)
            ctlast = int(line.strip())
            rcs = []
        else:
            strlist = line.strip().split(' ')
            intlist = []
            for string in strlist:
                intlist.append(int(string))
            rcs.append(intlist)
            ct-=1
        lct+=1
    f.close()
    sln = solve(rcs)
    if len(sln) != ctlast:
        print(sln)
    outputs.append(sln)
    return outputs        

def solve(rcs):
    #count them. odd numbers must be the ones
    heightcounts = {}
    for i in range(0,len(rcs)):
        for j in range(0,len(rcs[i])):
            if rcs[i][j] not in heightcounts:
                heightcounts[rcs[i][j]] = 0
            heightcounts[rcs[i][j]] += 1
    #get odds
    odds = []
    for height in heightcounts:
        if heightcounts[height]%2 == 1:
            odds.append(height)
    #sort the odd numbers. return
    odds = sorted(odds)
    return odds

infile_name = '/Users/pellowes/Downloads/B-small-attempt1.in'
#infile_name = '/Users/pellowes/Downloads/A-large(1).in'
#infile_name = '/Users/pellowes/dummydata'
outputs = readThroughDataGeneric(infile_name)
#print(len(outputs))
outfile_name = '/Users/pellowes/Downloads/out.out'
f = open(outfile_name,'w')
for i in range(0,len(outputs)):
    if i > 0:
        f.write('\n')
    
    f.write("Case #"+str(i+1)+": ")
    for j in range(0,len(outputs[i])):
        f.write(str(outputs[i][j]))
        if j < len(outputs[i])-1:
            f.write(' ')

f.close()