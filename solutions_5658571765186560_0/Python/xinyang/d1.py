# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 00:50:47 2015

@author: yx1992
"""

import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *

fin=open("D-small-attempt3.in",'r')
fout=open("D-output",'w')
num=int(fin.readline())
for i in range(num):  
    line=fin.readline()
    lines=string.split(line, " ")
    X=int(lines[0])
    R=int(lines[1])
    C=int(lines[2])
    if X>=8:
        fout.write("Case #"+str(i+1)+": RICHARD\n")
    elif (R*C)%X!=0:
        fout.write("Case #"+str(i+1)+": RICHARD\n")
    elif X>=2*C+1 or X>=2*R+1:
        #print(str(i+1)+'!!')
        fout.write("Case #"+str(i+1)+": RICHARD\n")
    elif X>C and X>R:
        fout.write("Case #"+str(i+1)+": RICHARD\n")
    elif (X==4 and R==2) or (X==4 and C==2) or (X==6 and R==2) or (X==6 and C==2) or (X==6 and R==3) or (X==6 and C==3) or (X==6 and R==4) or (X==6 and C==4) or (X==5 and R==2) or (X==5 and C==2) or (X==7 and R==2) or (X==7 and C==2) or (X==7 and R==3) or (X==7 and C==3) or (X==7 and R==4) or (X==7 and C==4):
        fout.write("Case #"+str(i+1)+": RICHARD\n")
    else:
        fout.write("Case #"+str(i+1)+": GABRIEL\n")
    #fout.write("Case #"+str(i+1)+": "+str(int(ans))+"\n")
    
fin.close();
fout.close();