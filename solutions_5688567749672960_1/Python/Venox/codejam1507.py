# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

import numpy as np
from collections import deque

def reverse(x):
    return int(str(x)[::-1])

def judge(n):
    if n<21:
        return n
    dic=set()
    cost=deque([1])
    num=deque([1])
    dic.add(1)
    while len(cost)!=0:
        
        nu=num.popleft()
        co=cost.popleft()

        nex=nu+1
        if nex==n:
            return co+1
        if not nex in dic:
            num.append(nex)
            cost.append(co+1)
            dic.add(nex)
        nex=reverse(nu)
        if nex==n:
            return co+1
        if not nex in dic:
            num.append(nex)
            cost.append(co+1)
            dic.add(nex)
            
def judge2(n):
    print n
    if n<1000:
        return judge(n)
    pre=0
    if n%10==0:
        n-=1
        pre=1
    s=str(n)[::-1]
    count=0
    for i,c in enumerate(s):
        if i<=(len(s)+1)/2-1:
            count +=int(c)*np.power(10,i)
        else:
            count +=int(c)*np.power(10,len(s)-1-i)
    print count,pre
    return count+judge2(np.power(10,len(s)-1))+pre
    
        
        
    
    
    
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):
        n=int(pf.readline())
        ans=judge2(n)
        anstr= "Case #"+str(qq+1)+": "+str(ans)
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('A-large.in')