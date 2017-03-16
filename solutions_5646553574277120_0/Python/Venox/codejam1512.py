# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

import numpy as np


def add1(c,d,v,cs):
    x=[0]*(v+1)
    x[0]=1
    for i in xrange(d):
        for j in xrange(v,-1,-1):
            if x[j]==1 and j+cs[i]<=v:
                x[j+cs[i]]=1
    return x
    
def judge1(c,d,v,cs):
    print c,d,v,cs
    x=add1(c,d,v,cs)
    #print x
    if all(np.array(x)>0):
        return 0
    cs.sort()
    if cs[0]!=1:
        cs.append(1)
        cs.sort()
        d+=1
        return 1+judge1(c,d,v,cs)
    su=0
    for i,cd in enumerate(cs):
        #print i,cd
        if su<cd-1:
            for j in xrange(su+1,cd):
                #print j
                if not j in cs:
                    cs.append(j)
                    d+=1
                    return 1+judge1(c,d,v,cs)
        su+=cd
    if su<v:
        for j in xrange(su+1,v+1):
            #print j
            if not j in cs:
                cs.append(j)
                d+=1
                return 1+judge1(c,d,v,cs)
    
    
        
        
    

            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):
        [c,d,v]=[int(x) for x in pf.readline().split(" ")]
        cs=[int(x) for x in pf.readline().split(" ")]
        ans=judge1(c,d,v,cs)
        anstr= "Case #"+str(qq+1)+": "+str(ans)
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('C-small-attempt1.in')