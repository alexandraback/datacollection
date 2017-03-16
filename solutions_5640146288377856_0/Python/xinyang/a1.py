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

def dislog(a):
    if a==0:
        return 0
    elif a==1:
        return 1
    else:
        return 1+dislog(floor(a/2))



fin=open("A-small-attempt0 (2).in",'r')
fout=open("A-output",'w')
num=int(fin.readline())
for j in range(num):
    line=fin.readline()
    lines=string.split(line, " ")
    R=int(lines[0])
    C=int(lines[1])
    W=int(lines[2])
    miss=(R-1)*ceil(C/(2*W-1))
    remain=C%(2*W-1)
    ans=floor(C/(2*W-1))-1+dislog(W-1)
    if C==W:
        ans=0
    elif C<2*W-1:
        ans=dislog(remain-1)
    elif remain>0:
        ans=max(floor(C/(2*W-1))-1+dislog(W-1),dislog(remain-1)+floor(C/(2*W-1)))
    fout.write("Case #"+str(j+1)+": "+str(int(ans+miss+W))+"\n")
    
fin.close();
fout.close();