from collections import defaultdict

lines = open('b.in').read().split("\n")
f = open('b.out', 'w')

n = int(lines[0])
for i in range(1, n+1):
    e, r, nn = ([long(x) for x in lines[2*i-1].split()])
    v = [long(x) for x in lines[2*i].split()]
    vs = defaultdict(list)
    for j in range(nn):
        vs[v[j]].append(j)
    vvs = []
    for j in sorted(vs.keys(), reverse=True):
        vvs.extend(vs[j])
    sp = [e]*nn
    ad = [0 for ii in range(nn)]
    res = 0
    for j in vvs:
        sp[j] = min(sp[j], e)
        res += sp[j] * v[j]
        v[j] = 0
        if ad[j] < 2:
            cur = sp[j] - r
        else:
            cur = sp[j]
        k = j-1
        while cur > 0 and k >= 0 and v[k] != 0:
            ad[k] += 1
            sp[k] = max(0, sp[k]-cur)
            k -= 1
            cur -= r
        if ad[j] < 2:
            cur = sp[j] - r
        else:
            cur = sp[j]
        k = j+1
        while cur > 0 and k < nn and v[k] != 0:
            ad[k] += 1
            sp[k] = max(0, sp[k]-cur)
            k += 1
            cur -= r
    print sp
    for j in range(nn):
        res += sp[j]*v[j]
    f.write("Case #%d: %s\n" % (i, res))

f.close()
