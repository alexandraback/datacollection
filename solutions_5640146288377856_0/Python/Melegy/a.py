'''
Created on May 2, 2015

@author: sshadmin
'''
from collections import deque

def solve(r,c,w):
    if c % w ==0:
        return (c/w)*r+w-1
    else:
        return (c/w)*r+w
    

fin=open('in','r') ; fout=open('out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    r,c,w=[int(x) for x in fin.readline().strip().split()]
    print case
    fout.write("Case #"+str(case)+": "+str(solve(r,c,w))+"\n")
    
    