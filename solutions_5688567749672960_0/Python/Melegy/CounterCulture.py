'''
Created on May 2, 2015

@author: sshadmin
'''
from collections import deque
import sys

def solve(n):
    d=deque([[1,1]])
    v=set()
    while len(d)>0:
        x,s=d.popleft()
        v.add(x)
        if x==n:
            return s
        if x+1 not in v:
            d.append([x+1,s+1])
            v.add(x+1)
        tmp=int(str(x)[::-1])
        if tmp not in v:
            d.append([tmp,s+1])
            v.add(tmp)
    

fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    n=int(fin.readline())
    print case
    fout.write("Case #"+str(case)+": "+str(solve(n))+"\n")
    
    