f = open("in.txt","r")
g = open("out.txt","w")

ad = []
vis = []
n = 0

def dfs(i):
    for ij in ad[i]:
        if ij in vis:
            return 1
        else:
            vis.append(ij)
            if dfs(ij)==1:
                return 1
    return 0

tcase = int(f.readline())+1
for t in range(1,tcase):
    n = int(f.readline())
    ad = []
    for i in range(n):
        ad.append([])
        st = f.readline().split()
        m = int(st[0])
        for j in range(m):
            ad[i].append(int(st[j+1])-1)
    for i in range(n):
        vis = [i]
        if dfs(i)==1:
            g.write("Case #"+str(t)+": Yes\n")
            n = -1
            break
    if n>=0:
        g.write("Case #"+str(t)+": No\n")

f.close()
g.close()