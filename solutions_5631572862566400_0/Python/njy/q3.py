
inp = open(r"C:\Users\t8319937\Downloads\C-small-attempt0.in",'r')
out = open(r"C:\Users\t8319937\Downloads\NirYa\q3.out", 'w')
l = inp.readlines()

def dfs1(idx, a, vis, scan_idx): #get circle masters
    if vis[idx] != False:
        if vis[idx] == scan_idx:
            return idx
        else:
            return -1
    else:
        vis[idx] = scan_idx
        return dfs1(a[idx], a, vis, scan_idx)

def dfs2(idx, a, root): #get length of chain
    if idx == root:
        return 1
    else:
        return 1 + dfs2(a[idx], a, root)

def dfs3(idx, a1): #get h
    if len(a1[idx]) == 0:
        return 1
    else:
        return 1 + max([dfs3(nei, a1) for nei in a1[idx]])

res = []
rounds = int(l[0])
for i in range(rounds):
    n = int(l[1+2*i])
    a = [-1] + [int(v) for v in l[2+2*i].split(" ")]
    vis = [False for i in range(n+1)]
    roots = []
    for j in range(1,n+1):
        t = dfs1(j,a,vis,j)
        if t != -1:
            roots.append( (dfs2(a[t],a,t), t) )

    best = max(roots)[0]
    opt = [idx for idx in range(1,n+1) if a[a[idx]] == idx]
    a1 = [[] for j in range(n+1)] #inverse
    for j in range(1,n+1):
        if a[a[j]] != j: #dont take pair
            a1[a[j]].append(j)

    h = [dfs3(idx,a1) for idx in opt]
    res.append(max(sum(h),best))

for k in range(rounds):
    out.write("Case #{0}: {1}\n".format(k+1,res[k]))
out.close()