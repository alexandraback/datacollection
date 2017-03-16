# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 16:21:37 2015

@author: yx1992
"""

fin=open("A-small-attempt1.in",'r')
fout=open("A-output",'w')
num=int(fin.readline())
for i in range(num):
    line=fin.readline()
    print line
    maxshy=line[0]
    shy=[]
    a=0
    b=0
    #print (len(line))
    print(len(line))
    for j in range(len(line)-3):
        if j>a:
            b+=j-a
            a=j+int(line[j+2])
        else:
            a+=int(line[j+2])
    fout.write("Case #"+str(i+1)+": "+str(b)+"\n")
    print "Case #"+str(i+1)+": "+str(b)
    
fin.close();
fout.close();