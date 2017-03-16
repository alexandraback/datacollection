from copy import deepcopy
fi=open('inp.in','r')
fo=open('outp.in','w')

t=int(fi.readline().rstrip('\n'))
outs=''
for case in range(1,t+1):
    b,m=map(int,fi.readline().rstrip('\n').split(' '))
    grid=[[0 for i in range(b)] for j in range(b)]
    p=1
    ans=''
    for i in range(1,b):
        if p>=m:
            break
        else:
            p*=i
    else:
        if p<=m:
            ans='IMPOSSIBLE'
            outs+=('Case #'+str(case)+': '+ans+'\n')
            continue
    dfs=[]
    dfs.append([-1,1,[1]])
    while m and len(dfs):
        t=dfs.pop()
        if t[1]==b:
            m-=1
            for i in range(1,len(t[2])):
                grid[t[2][i-1]-1][t[2][i]-1]=1
        else:
            for i in range(1,b+1):
                if i not in t[2]:
                    te=deepcopy(t[2])
                    te.append(i)
                    dfs.append([t[1],i,te])
    ans+='POSSIBLE\n'
    for i in range(b):
        for j in range(b):
            ans+=str(grid[i][j])
        ans+='\n'
    outs+=('Case #'+str(case)+': '+ans)
outs=outs.rstrip('\n')
fo.write(outs)
fi.close()
fo.close()