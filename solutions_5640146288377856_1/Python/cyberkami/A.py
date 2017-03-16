# -*- coding: utf-8 -*-
"""
Created on Sun May 10 17:57:52 2015

@author: cyber
"""

T = int(input())

def fct():
    (R,C,W) = map(int,input().split())
    if C%W ==0:
        ans = (C//W)*R+(W-1)            
    else:
        ans = (C//W)*R+W
    print(ans)

for test in range(T):
    print ('Case #%d:' % (test+1), end=' ')	
    fct()

