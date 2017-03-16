# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 09:39:30 2016

@author: David
"""

fin = file("file.in",'r')
fout = file("file.out",'w')
i = int(fin.readline())
for l in range(i):
    s = fin.readline().strip()
    goal = ''.join(['+' for i in range(len(s))])
    seen = {s:1}
    q = [(s,0)]
    while not len(q) == 0:
        #print q
        t,d = q.pop(0)
        #print t,d,'*'
        if t == goal:
            fout.write("Case #%d: %d\n"%(l+1,d))
            break
        for i in range(1,len(s)+1):
            c = (t[:i])[::-1]
            c = ''.join(['+' if x == '-' else '-' for x in c])+t[i:]
            if c not in seen.keys():
                #print c,i
                seen[c] = 1
                q.append((c,d+1))
    
        
    



fin.close()
fout.close()