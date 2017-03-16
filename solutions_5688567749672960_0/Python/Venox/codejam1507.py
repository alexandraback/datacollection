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
        
        
    
    
    
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):
        n=int(pf.readline())
        ans=judge(n)
        anstr= "Case #"+str(qq+1)+": "+str(ans)
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('A-small-attempt1.in')