# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 17:59:38 2015

@author: yx1992
"""

import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *
#
#count=zeros((1000,1000,2),dtype=int)
#for k in range(10):
#    for i in range(1000):
#        for j in range(1000):
#            if j+1<(i+1)*(2**0)+1:
#                count[i][j][1]=j+1
#            elif (i+1)*(2**k)+1<=j+1<=(i+1)*(2**(k+1)):
#                count[i][j][0]=count[i][ceil(float(j+1)/2.0)-1][0]+count[i][floor(float(j+1)/2.0)-1][0]+1
#                count[i][j][1]=maximum(count[i][ceil(float(j+1)/2.0)-1][1],count[i][ceil(float(j+1)/2.0)-1][1])
#                #print("i="+str(i)+", j= "+str(j))
#print count

fin=open("B-small-attempt3.in",'r')
fout=open("B-output",'w')
num=int(fin.readline())
for i in range(num):
    D=int(fin.readline())    
    line=fin.readline()
    lines=string.split(line, " ")
    #print(len(lines))
    cookie=np.array([int(j) for j in lines])
    ans=np.max(cookie)
    #print(ans)
    for j in range(1,np.max(cookie)+1):
        sub=0
        temp=0
        for k in cookie:
            if k>j:
                temp+=ceil(float(k)/j)-1
                sub=maximum(sub,ceil(k/ceil(float(k)/j)))
                print(k,j,ceil(k/ceil(float(k)/j)))
            else:
                sub=maximum(sub,k)
        temp=temp+sub   
        if temp<ans:
            ans=temp

    fout.write("Case #"+str(i+1)+": "+str(int(ans))+"\n")
    
fin.close();
fout.close();