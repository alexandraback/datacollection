# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""

def judge(x,r,c):
    can='GABRIEL'
    cant='RICHARD'
    if r<c:
        r,c=c,r
    if x>=7:
        return cant
    elif x==1:
        return can
    elif x==2:
        return can if r*c%2==0 else cant
    elif x==3:
        return can if r*c%3==0 and c>1 and r>=3 else cant
    elif x==4:
        return can if r*c%4==0 and c>2 and r>=4  else cant
    elif x==5:
        return can if r*c%5==0 and c>2 and r>=5  else cant
    elif x==6:
        return can if r*c%6==0 and c>3 and r>=6  else cant
    
            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for i in xrange(t):
        inp=pf.readline().split(" ")
        ans=judge(int(inp[0]),int(inp[1]),int(inp[2]))
        anstr= "Case #"+str(i+1)+": "+ans
        print anstr
        anstr+='\n'
        wf.write(anstr)
        
        
        
    
    pf.close()
    wf.close()
    
    
reader('D-large.in')