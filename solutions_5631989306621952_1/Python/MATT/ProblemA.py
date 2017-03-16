# -*- coding: utf-8 -*-
"""
Created on Sat Apr 16 02:08:23 2016

@author: mtrager
"""



def BestAlpha(s):
    L=len(s)
    string=s[0]
    for i in range(1,L):
        if s[i]<string[0]:
            string=string+s[i]
        else:
            string=s[i]+string
    return string
        
        


# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    s=raw_input().strip()  # read a list of integers, 2 in this case
    
    string=BestAlpha(s)
    
    print "Case #{}: {}".format(i, string)
  # check out .format's specification for more formatting options