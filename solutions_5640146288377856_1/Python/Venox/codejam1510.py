# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

import numpy as np


def judge(r,c,w):
    ans=(r-1)*(c/w)
    while c>2*w-1:
        ans+=1
        c-=w
    if c==w:
        return ans+w
    else:
        return ans+w+1
        
        
        
    

            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):
        [r,c,w]=[int(x) for x in pf.readline().split(" ")]
        ans=judge(r,c,w)
        anstr= "Case #"+str(qq+1)+": "+str(ans)
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('A-large.in')