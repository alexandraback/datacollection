# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 16:21:37 2015

@author: yx1992
"""
import string

fin=open("A-large.in",'r')
fout=open("A-output",'w')
num=int(fin.readline())
for i in range(num):
    line=fin.readline()
    print line
    lines=string.split(line, " ")
    maxshy=int(lines[0])
    shy=[]
    a=0
    b=0
    #print (len(line))
    print(len(lines[1]))
    for j in range(len(lines[1])-1):
        if j>a:
            b+=j-a
            a=j+int(lines[1][j])
        else:
            a+=int(lines[1][j])
    fout.write("Case #"+str(i+1)+": "+str(b)+"\n")
    print "Case #"+str(i+1)+": "+str(b)
    
fin.close();
fout.close();