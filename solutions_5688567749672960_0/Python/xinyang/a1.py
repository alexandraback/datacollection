# -*- coding: utf-8 -*-
"""
Created on Sat May 02 08:53:26 2015

@author: yx1992
"""


import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *

def rev(num):
    if num < 10:
        return num
    else:
        ones = num % 10
        rest = num // 10
        return ones * 10 ** int(log10(rest) + 1) + rev(rest)

def mincount(num,goal):
    #print "num: "+str(num)
    #print "goal: "+str(goal)
    if goal<=20:
        return goal
    elif num==1:
        return 10+mincount(10,goal)
    elif goal%10==0:
        return 1+mincount(num,goal-1)
    elif floor(log10(num))<floor(log10(goal)):
        n=floor(log10(num))+1
        if n%2==0:
            return 2*10**(n/2)-1+mincount(10**(n),goal)
        else:
            return 10**((n+1)/2)+10**((n-1)/2)-1+mincount(10**(n),goal)
    else:
        n=floor(log10(num))+1
        if n%2==0:
            front=floor(goal/(10**(n/2)))
            back=goal%(10**(n/2))
            #print "front: "+str(front)
            #print "back: "+str(back)
            fix=0
            if front==10**((n/2)-1):
                fix=1
            return rev(front)+back-fix
        else:
            front=floor(goal/(10**((n+1)/2)))
            back=goal%(10**((n+1)/2))
            fix=0
            if front==10**((n-3)/2):
                fix=1
            #print "front: "+str(front)
            #print "back: "+str(back)
            return rev(front)+back-fix
            


fin=open("A-small-attempt4.in",'r')
fout=open("A-output",'w')
num=int(fin.readline())
for i in range(num):
    N=int(fin.readline())    
            


    fout.write("Case #"+str(i+1)+": "+str(int(mincount(1,N)))+"\n")
    
fin.close();
fout.close();