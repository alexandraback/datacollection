# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

import numpy as np
import re

def judge1(k,l,s,keys,target):
    for i in target:
        if not i in keys:
            return 0.0
    maxnum=0
    total=0
    reg=re.compile("(?="+target+")")
    for i in xrange(k**s):
        ks=''
        for j in xrange(s):
            x=i%k
            ks+=keys[x]
            i/=k
        #print ks
        count=len(reg.findall(ks))

        #print count
        total+=count
        if maxnum<count:
            maxnum=count 
    return float(maxnum)-float(total)/(k**s)
        
        
        
    

            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for qq in xrange(t):
        [k,l,s]=[int(x) for x in pf.readline().split(" ")]
        keys=pf.readline()[:k]
        target=pf.readline()[:l]
        ans=judge1(k,l,s,keys,target)
        anstr= "Case #"+str(qq+1)+": "+"%.6f"%ans
        print anstr
        anstr+='\n'
        wf.write(anstr)
    
    pf.close()
    wf.close()
    
    
reader('B-small-attempt1.in')