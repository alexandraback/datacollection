fin = open("in.in")
fout = open("out.out","w")
data = fin.read().split("\n")
T = int(data.pop(0))
fin.close()
        
def cal(i):
    global m, s1, s2, n, r
    p = q = False
    if i == n:
        for j in range(n):
            if not r[j] and not (s1[l[j][0]] and s2[l[j][1]]):
                return
        if m < n - sum(r):
            m = n - sum(r)
        return
    r[i] = True
    p =s1[l[i][0]]
    q =s2[l[i][1]]
    s1[l[i][0]] = True
    s2[l[i][1]] = True
    cal(i+1)
    s1[l[i][0]] = p
    s2[l[i][1]] = q
    r[i] = False
    p =s1[l[i][0]]
    q =s2[l[i][1]]
    s1[l[i][0]] = False or p
    s2[l[i][1]] = False or q
    cal(i+1) 
    s1[l[i][0]] = p
    s2[l[i][1]] = q
    
for i in range(1, T+1):
    n = int(data.pop(0))
    m = 0
    l = []
    r = []
    s1 = {}
    s2 = {}
    for j in range(n):
        l += [data.pop(0).split(' '), ]
        s1[l[j][0]] = False
        s2[l[j][1]] = False
        r += [False]
    cal(0)
    print >>fout, "Case #%d: %d" % (i, m)
fout.close()