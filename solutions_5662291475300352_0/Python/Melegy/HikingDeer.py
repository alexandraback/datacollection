'''
Created on May 2, 2015

@author: sshadmin
'''
def solve(h):
    if len(h)==1 and h[0][1]==1:
        return 0
    if len(h)==1:
        h[0]=[h[0][0],h[0][1],h[0][2]]
        h.append([h[0][0],h[0][1],h[0][2]+1])
    if h[0][2]==h[1][2]:
        return 0
    if h[0][2]>h[1][2]:
        slow=[h[0][0],h[0][2]]
        fast=[h[1][0],h[1][2]]
    else:
        fast=[h[0][0],h[0][2]]
        slow=[h[1][0],h[1][2]]
    tslow=((360-slow[0])/360.0)*slow[1]
    tfast=((360-fast[0])/360.0)*fast[1]+fast[1]
    
    if tslow>=tfast:
        return 1
    else:
        return 0
    
    
fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    n=int(fin.readline().strip())
    h=[]
    for i in range(n):
        h.append([int(x) for x in fin.readline().strip().split()])
    fout.write("Case #"+str(case)+": "+str(solve(h))+"\n")
    
    