# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""
def judge(n,s):
    x=0
    su=0
    for i in xrange(n+1):
        if su>=i:
            su+=int(s[i])
        else :
            x+=i-su
            su=i+int(s[i])
    return x
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for i in xrange(t):
        inp=pf.readline().split(" ")
 
        ans=judge(int(inp[0]),inp[1])
        anstr= "Case #"+str(i+1)+": "+str(ans)
        anstr+='\n'
        wf.write(anstr)
        
        
        
    
    pf.close()
    wf.close()
    
    
reader('A-large.in')