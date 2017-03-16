# -*- coding: utf-8 -*-
"""
Created on Sun May 10 03:20:17 2015

@author: yx1992
"""

# -*- coding: utf-8 -*-
"""
Created on Sun May 10 01:59:46 2015

@author: yx1992
"""

import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *
from scipy.spatial import ConvexHull
from scipy.spatial import Delaunay


        

fin=open("B-small-attempt0 (1).in",'r')
fout=open("B-output",'w')
num=int(fin.readline())
for j in range(num):
    line=fin.readline()
    lines=string.split(line, " ")
    K=int(lines[0])
    L=int(lines[1])
    S=int(lines[2])
    letter=[]
    count=[]
    source=fin.readline()    
    target=fin.readline()
    for k in range(K):
        if source[k] not in letter:
            letter.append(source[k])
            count.append(1)
        else:
            for i in range(size(letter)):
                if letter[i]==source[k]:
                    count[i]+=1
    prob=1
    #print count
    for l in range(L):
        mark=False
        for i in range(size(letter)):
            if letter[i]==target[l]:
                prob*=(count[i]*1.0/K)
                mark=True
                break
        if mark==False:
            prob=0
            break

    maxlen=0
    for k in range(1,L):
        mark=True
        for h in range(L-k):
            if target[h]!=target[k+h]:
                mark=False
                break
        if mark:
            maxlen=max(maxlen,L-k)
    ans=0.0
    #print prob
    if prob!=0:
        ans=1+(S-L)/(L-maxlen)-(S-L+1)*prob 
    ans=round(ans,7)               
    print ans
    fout.write("Case #"+str(j+1)+": "+str(ans)+"\n")
    
fin.close();
fout.close();