import sys
sys.setrecursionlimit(5000)

inp = open(r"F:\Nir\Downloads\C-small-attempt0.in",'r')
out = open(r"F:\Nir\Downloads\njy\q3.out", 'w')
l = inp.readlines()

#def dfs(x, vis, comp_idx): #get components
#    if vis[x] == -1:
#        vis[x] = comp_idx
#        for p in nei[x]:
#            dfs(p, vis, comp_idx)

res = []
t = int(l[0])
idx = 1
for i in range(t):
    n = int(l[idx])
    idx += 1

    ctr = 0
    nei = dict()
    for i in range(n):
        f,s = l[idx].split(" ")
        idx += 1

        if (f+"0") not in nei:
            nei[f+"0"] = set()
        if (s+"1") not in nei:
            nei[s+"1"] = set()
        
        if len(nei[f+"0"]) >= 1 and len(nei[s+"1"]) >= 1:
            ctr += 1
            
        nei[f+"0"].add(s+"1")
        nei[s+"1"].add(f+"0")

    #vis = {k:-1 for k in nei.keys()}
    #comp = 0
    #for x in nei.keys():
    #    if vis[x] == -1:
    #        dfs(x,vis,comp)
    #        comp += 1

    #res.append(n-len(nei)-comp)

    res.append(ctr)

for k in range(t):
    out.write("Case #{0}: {1}\n".format(k+1,res[k]))
out.close()