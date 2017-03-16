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
            s = line.strip()
            outputs.append(solve(s))
        lct+=1
    f.close()
    return outputs        

def solve(s):
    #only mutual bffs allow anything other than a 1-directional circle
    maxchar = s[0]
    string = s[0]
    for i in range(1,len(s)):
        if s[i] >= maxchar:
            maxchar=s[i]
            string=s[i]+string
        else:
            string=string+s[i]
    return string

infile_name = '/Users/pellowes/Downloads/A-small-attempt0(1).in'
#infile_name = '/Users/pellowes/Downloads/C-large.in'
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