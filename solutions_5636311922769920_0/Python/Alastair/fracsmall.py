def path(a, l, n):
    if n==1:
        return l[0]
    else:
        return a * path(a,l[1:] if len(l)>1 else l,n-1) + l[0]
lines = open("fracin.txt").read().splitlines()
out = ""
for i in xrange(1, len(lines)):
    K = int(lines[i].split()[0])
    C = int(lines[i].split()[1])
    S = int(lines[i].split()[2])
    partsrem = range(K)
    parts = []
    while len(partsrem)>C:
        parts.append(partsrem[:C])
        newParts = partsrem[C:]
        partsrem = newParts
    parts.append(partsrem)
    #print parts
    res = [str(path(K, j, C)+1) for j in parts]
    out+="Case #"+str(i)+": "+(" ".join(res) if len(res) <= S else "IMPOSSIBLE")+"\n"
open("fracout.txt","w").write(out)

