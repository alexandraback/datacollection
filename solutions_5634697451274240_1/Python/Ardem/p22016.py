# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 09:39:30 2016

@author: David
"""
fin = file("file.in",'r')
fout = file("file2.out",'w')
i = int(fin.readline())
for l in range(i):
    s = fin.readline().strip()
    prev = '+'
    count = 0
    for i,c in enumerate(s[::-1]):
        if c != prev:
            prev = c
            count += 1
    
    fout.write("Case #%d: %d\n"%(l+1,count))
    

fin.close()
fout.close()