# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

import numpy as np


def judge1(n,ps):
    start=[]
    speed=[]
    for i in xrange(n):
        if ps[i][1]==1:
            start.append(ps[i][0])
            speed.append(360.0/ps[i][2])
        else:
            for j in xrange(ps[i][2]):
                start.append(ps[i][0])
                speed.append(360.0/(ps[i][2]+j))    
    #print start,speed
    if len(start)==1:
        return 0  
    if (360-start[0])/speed[0]>=(720-start[1])/speed[1] or (360-start[1])/speed[1]>=(720-start[0])/speed[0]:
        return 1
    else:
        return 0      
        
        
        
    

            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):
        n=int(pf.readline())
        ps =[]
        for i in xrange(n):
            ps.append([int(x) for x in pf.readline().split(" ")])
        ans=judge1(n,ps)
        anstr= "Case #"+str(qq+1)+": "+str(ans)
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('C-small-1-attempt1.in')