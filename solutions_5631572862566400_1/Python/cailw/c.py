from collections import deque

title='c'

with open('%s.txt'%title) as fi, open('%s_o.txt'%title,'w') as fo:
    def readint():
        return int(fi.readline().strip())
    def readints():
        return list(map(int,fi.readline().split()))
    t=readint()
    for icase in range(1,t+1):
        def print_case(*args):
            print('Case #%d:'%icase,*args,file=fo)
        n=readint()
        bff=readints()
        bff=[0]+bff
        rev=dict((i,[]) for i in range(1,n+1))
        for i in range(1,n+1):
            rev[bff[i]].append(i)
        visited=[False]*(n+1)
        typeB=[]
        for i in range(1,n+1):
            if bff[bff[i]]!=i or visited[i]:
                continue
            visited[i]=True
            visited[bff[i]]=True
            typeBans=2
            for root in [i,bff[i]]:
                deq=deque()
                ts=[-1]*(n+1)
                ts[i]=0
                ts[bff[i]]=0
                deq.append((root,0))
                while len(deq)>0:
                    curr,tc=deq.popleft()
                    ts[curr]=tc
                    for nghbr in rev[curr]:
                        if ts[nghbr]>=0:
                            continue
                        deq.append((nghbr,tc+1))
                        ts[nghbr]=tc+1
                        visited[nghbr]=True
                typeBans+=max(ts)
            typeB.append(typeBans)
        ans=[0]
        for root in range(1,n+1):
            if visited[root]:
                continue
            ts=[0]*(n+1)
            ts[root]=1
            tc=1
            curr=bff[root]
            while ts[curr]==0:
                tc+=1
                ts[curr]=tc
                curr=bff[curr]
            else:
                ans.append(tc-ts[curr]+1)
        print_case(max(max(ans),sum(typeB)))
