'''
Created on May 2, 2015

@author: sshadmin
'''
from itertools import combinations

def comb(num,v,c):
    r=[]
    def helper(num,v,c):
        if num==0:
            r.append(1)
        for i in range(len(v)):
            if num-v[i]>=0:
                helper(num-v[i],v[i+1::],c+[v[i]])
    helper(num,v,c)
    if len(r)>0:
        return True
    else:
        return False
    

def suffice(v,coins):
    for i in range(1,v+1):
        if not comb(i,coins,[]):
            return False
    return True
    
      
def solve(c,d,v,coins):
    if suffice(v,coins):
        return 0
    remaining=list(set(range(1,v+1))-set(coins))
    
    for i in range(len(remaining)):
        combi=list(combinations(remaining,i))
        for add in combi:
            tmp=coins+list(add)
            if suffice(v,tmp):
                return i
    
fin=open('in','r') ; fout=open('out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    print case
    c,d,v=[int(x) for x in fin.readline().strip().split()]
    coins=[int(x) for x in fin.readline().strip().split()]
    fout.write("Case #"+str(case)+": "+str(solve(c,d,v,coins))+"\n")
    
    