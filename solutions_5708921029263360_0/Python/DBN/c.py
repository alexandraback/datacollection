import math
fout = open('c.out', 'w')
fin = open('C-small-attempt1.in', 'r')

def dfs(j,p,s):
    g = '{} {} {}'.format(j,p,s)

    jps = int('{}{}'.format(j,p))
    pss = int('{}{}'.format(p,s))
    sjs = int('{}{}'.format(s,j))

    if g not in garnets and jp[jps] < tk and ps[pss] < tk and sj[sjs] < tk:
        garnets.append(g)
        jp[jps] += 1
        ps[pss] += 1
        sj[sjs] += 1


    if j < tj:
        dfs(j+1,p,s)
    if p < tp:
        dfs(j,p+1,s)
    if s < ts:
        dfs(j,p,s+1)



t = int(fin.readline())
for x in range(1,t+1):
    ins = fin.readline().split(" ")
    global tj
    tj = int(ins[0])
    global tp
    tp = int(ins[1])
    global ts
    ts = int(ins[2])
    global tk
    tk = int(ins[3])

    global jp
    jp = dict.fromkeys(range(1,1020), 0)
    global ps
    ps = dict.fromkeys(range(1,1020), 0)
    global sj
    sj = dict.fromkeys(range(1,1020), 0)

    global garnets
    garnets = []

    dfs(1,1,1)
    fout.write('Case #{}: {}\n'.format(x, len(garnets)))
    for g in garnets:
        fout.write('{}\n'.format(g))
