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
            pass          
        else:
            #get the number, run the solver
            numtocheck = int(line.strip())
            outputs.append(solve(numtocheck))
        lct+=1
    f.close()
    return outputs        
        
def charToInt(c):
    if c == 'R':
        return 1
    if c == 'B':
        return 2
    else:
        RuntimeError("Illegal Character in Game")

def solve(basenumber):
    uniquedigits = set()
    for i in range(1,101):
        newnumber = basenumber*i
        strnumber = str(newnumber)
        for digit in strnumber:
            uniquedigits.add(digit)
        if(len(uniquedigits) == 10):
            return newnumber
    return "INSOMNIA"
    


infile_name = '/Users/pellowes/Downloads/A-small-attempt0.in'
#infile_name = '/Users/pellowes/dummydata'
outputs = readThroughDataGeneric(infile_name)
print(len(outputs))
outfile_name = '/Users/pellowes/Downloads/out.out'
f = open(outfile_name,'w')
for i in range(0,len(outputs)):
    if i > 0:
        f.write('\n')
    f.write("Case #"+str(i+1)+": "+str(outputs[i]))
f.close()