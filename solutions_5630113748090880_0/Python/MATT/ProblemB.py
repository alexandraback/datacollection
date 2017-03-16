# -*- coding: utf-8 -*-
"""
Created on Sat Apr 16 03:19:09 2016

@author: mtrager
"""

import numpy as np

def FindMissingLine(lines):
    l=[int(i) for row in lines for i in row]
    newline=[]
    for i in l:
        count=l.count(i)
        if count%2==1:
            if i not in newline:
                newline.append(i)
    newline.sort()
    return newline
    
    


# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    N, = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
    lines=np.zeros((2*N-1,N))   
    for j in range(2*N-1):
        lines[j]=[int(s) for s in raw_input().split(" ")]
    
    NewLine=FindMissingLine(lines)
    
    NewLineString=" ".join(str(e) for e in NewLine)
    
    print "Case #{}: {}".format(i, NewLineString)
    
  # check out .format's specification for more formatting options