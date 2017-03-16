# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 09:05:46 2016

@author: David
"""

fin = file("file.in",'r')
fout = file("file.out",'w')
i = int(fin.readline())
for l in range(i):
    c = int(fin.readline())
    if c == 0:
        fout.write("Case #%d: INSOMNIA\n"%(l+1))
        continue
    d = [0 for k in range(10)]
    n = 1
    while sum(d)<10:
        t = str(c*n)
        for char in t:
            if d[int(char)] == 0:
                #print l,int(char)
                d[int(char)] = 1
        n+=1
        #print d,t
    fout.write("Case #%d: %d\n"%(l+1,c*(n-1)))
fin.close()
fout.close()
    
    