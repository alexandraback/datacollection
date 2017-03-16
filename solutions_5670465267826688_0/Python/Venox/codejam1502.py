# -*- coding: utf-8 -*-
"""
Created on Sat Apr 11 09:30:45 2015

@author: liujingjie
"""
def calc(tar,s):
    ke=[[0,1,2,3],
        [1,4,3,6],
        [2,7,4,1],
        [3,2,5,4],
        [4,5,6,7],
        [5,0,7,2],
        [6,3,0,5],
        [7,6,1,0]]
    state=0
    for j,i in enumerate(s):
        state=ke[state][i]
        if state==tar:
            return True,j+1
    return False,0
    
def null(s):
    ke=[[0,1,2,3],
        [1,4,3,6],
        [2,7,4,1],
        [3,2,5,4],
        [4,5,6,7],
        [5,0,7,2],
        [6,3,0,5],
        [7,6,1,0]]
        
    state=0
    for j,i in enumerate(s):
        state=ke[state][i]
    return state==0
def judge(n,x,iss):
    s=[0]*n
    for i,k in enumerate(iss):
        if k=='i':
            s[i]=1
        elif k=='j':
            s[i]=2
        else:
            s[i]=3
    st=[]+s
    x-=1
    c=1
    while x>0:
        st+=s
        x-=1;
        c+=1;
        if c==4:
            break
    pa,num=calc(1,st)
    if not pa:
        return 'NO'
    st=st[num:]
    c=0
    while x>0:
        st+=s
        x-=1;
        c+=1;
        if c==4:
            break
    pa,num=calc(2,st)
    if not pa:
        return 'NO'
    st=st[num:]
    c=0
    while x>0:
        st+=s
        x-=1;
        c+=1;
        if c==4:
            break
    pa,num=calc(3,st)
    if not pa:
        return 'NO'
    st=st[num:]
    while x>0:
        st+=s
        x-=1;
    return 'YES' if null(st) else 'NO'
    
    
            
        
    
        
def reader(name):
    pf=open(name,'r')
    wf=open("ans",'w')
    t=int(pf.readline())
    for i in xrange(t):
        inp=pf.readline().split(" ")
        s=pf.readline()
        ans=judge(int(inp[0]),int(inp[1]),s[0:int(inp[0])])
        anstr= "Case #"+str(i+1)+": "+ans
        anstr+='\n'
        wf.write(anstr)
        
        
        
    
    pf.close()
    wf.close()
    
    
reader('C-small-attempt3.in')