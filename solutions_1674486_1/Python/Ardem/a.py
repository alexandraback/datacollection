fin=open('in.txt','r')
fout=open('out.txt','w')

d=int(fin.readline())
for l in range(d):
    n=int(fin.readline())
    paths=[[] for i in range(n)]
    found=False
    for i in range(n):
        paths[i]+=(map(lambda x:x-1,map(int,fin.readline().split())[1:]))
    for i in range(n):
        q=[i]
        cur=0
        seen = [False for j in range(n)]
        while cur < len(q):
            if seen[q[cur]]:
                found=True
                break
            seen[q[cur]]=True
            for p in paths[q[cur]]:
                q.append(p)
            if found:
                break
            cur+=1
        if found:
            fout.write("Case #%d: Yes\n"%(l+1))
            break
    if not found:
        fout.write("Case #%d: No\n"%(l+1))
fin.close()
fout.close()
                    
            
    
    
