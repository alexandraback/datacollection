# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 22:29:09 2015

@author: yx1992
"""
import string
import numpy as np
import scipy as sp
from numpy import *
from scipy import *

def product(a,b):
    if a==0 :
        return b
    elif b==0:
        return a
    elif a==4 :
        return (b+4)%8
    elif  b==4:
        return (a+4)%8
    elif a==b:
        return 4
    elif a>4:
        return (4+product(a-4,b))%8
    elif b>4:
        return (4+product(a,b-4))%8
    elif b==a+1 or b==(a+1)%3:
        if a==1:
            return 3
        else:
            return (a+2)%3
    elif b==a+2 or b==(a+2)%3:
        if a==2:
            return 7
        else:
            return 4+(a+1)%3
    print("error !")
    
fin=open("C-large.in",'r')
fout=open("C-output",'w')
num=int(fin.readline())
for i in range(num):

    line=fin.readline()
    line=string.split(line, " ")  
    #print line
    length=line[0]
    #print length
    lines=fin.readline()
    ans=0
    for j in range(int(length)):
        
        if lines[j]=='i':
            ans=product(ans,1)
        elif lines[j]=='j':
            ans=product(ans,2)
        elif lines[j]=='k':
            ans=product(ans,3)
        #print ("ans="+str(ans))
    if int(line[1])%4==0:
        ans=0
    elif int(line[1])%4==2:
        ans=product(ans,ans)
    elif int(line[1])%4==3:
        temp=ans
        ans=product(ans,temp)
        ans=product(ans,temp)
    #print ("final ans="+str(ans))
    if ans==4:
        icount=0
        kcount=0
        #find first i
        imark=False
        kmark=False
        for im in range(4):
            #print("im = "+str(im))

            for imm in range(int(length)):
                        if lines[imm]=='i':
                            icount=product(icount,1)
                        elif lines[imm]=='j':
                            icount=product(icount,2)
                        elif lines[imm]=='k':
                            icount=product(icount,3)
                        if(icount==1):
                            imark=True
                            break            
            if imark==True:
                break
        for km in range(4):

            for kmm in range(int(length)):
                        if lines[int(length)-1-kmm]=='i':
                            kcount=product(1,kcount)
                        elif lines[int(length)-1-kmm]=='j':
                            kcount=product(2,kcount)
                        elif lines[int(length)-1-kmm]=='k':
                            kcount=product(3,kcount)
                        if(kcount==3):
                            kmark=True
                            break              
            if kmark==True:
                break

        if imark and kmark and (im+km)*int(length)+kmm+imm+2<=int(length)*int(line[1]):
            fout.write("Case #"+str(i+1)+": YES\n")
        else:
            fout.write("Case #"+str(i+1)+": NO\n")
    else:
        fout.write("Case #"+str(i+1)+": NO\n")

    
fin.close();
fout.close();