'''
Created on May 6, 2012

@author: tfranovic
'''
import sys
def check(i,adj):
    q=[]
    s=i
    got=[0]*(N+1)
    for c in adj[i]:
        q.append(c)
    while(len(q)>0):
        s=q.pop()
        got[s]=got[s]+1
        if(got[s]>=2):
            return True
        for c in adj[s]:
            q.append(c)
    return False
            
inName=sys.argv[1]
outName=inName.replace('.in', '.out')
f1=open(inName, 'r')
out=''
T=int(f1.readline())
for k in range(1,T+1):
    N=int(f1.readline())
    adj={}
    res=False
    for i in range(1,N+1):
        if(not i in adj):
                adj[i]=[]
        l=(f1.readline().rstrip()).split(' ')
        for j in l[1:]:
            adj[i].append(int(j))
    for i in range(1,N+1):
        res=check(i,adj)
        if(res):
            break
    if(res):    
        out+='Case #' + str(k)+': Yes\n'
    else:
        out+='Case #' + str(k)+': No\n'
f1.close()
f2=open(outName,'w+')
f2.write(out.rstrip("\n"))
f2.close()