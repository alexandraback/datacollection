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
            #run the solver
            l = line.strip()
            seriestocheck=np.zeros(len(l),dtype=np.bool)
            for i in range(0,len(l)):
                character = l[i]
                if character=='+':
                    seriestocheck[i]=True
            outputs.append(solve(seriestocheck))
        lct+=1
    f.close()
    return outputs        
        

def solve(series):
    prev_val = True
    changes = 0    
    for i in range(len(series)-1,-1,-1):
        if(prev_val != series[i]):
            changes+=1
            prev_val = series[i]
    return changes
    


#infile_name = '/Users/pellowes/Downloads/B-small-attempt0.in'
infile_name = '/Users/pellowes/Downloads/B-large.in'
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