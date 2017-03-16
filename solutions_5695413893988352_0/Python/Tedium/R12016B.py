from string import *

def finish (p, a, b, ca, cb):
    if p == len(a):
        return (ca, cb)
    if ca == cb:
        print("ERROR")
    if ca > cb:
        for i in range(p, len(a)):
            ca = ca * 10
            cb = cb * 10
            if a[i] != '?':
                ca += int(a[i])
            if b[i] == '?':
                cb += 9
            else:
                cb += int(b[i])
        return (ca, cb)
    else:
        for i in range(p, len(a)):
            ca = ca * 10
            cb = cb * 10
            if b[i] != '?':
                cb += int(b[i])
            if a[i] == '?':
                ca += 9
            else:
                ca += int(a[i])
        return (ca, cb)

def dfs (p, a, b, ca, cb):
    if p == len(a):
        return (ca, cb)

    if a[p] != '?':
        if b[p] != '?':
            if a[p] == b[p]:
                return dfs(p+1, a, b, ca*10+int(a[p]), cb*10+int(b[p]))
            else:
                return finish(p+1, a, b, ca*10+int(a[p]), cb*10+int(b[p]))
        else: #b[p] == '?'
            (oa1, ob1) = dfs(p+1, a, b, ca*10+int(a[p]), cb*10+int(a[p]))
            (oa2, ob2) = (1e100, 0)
            (oa3, ob3) = (1e100, 0)
            if int(a[p]) < 9:
                (oa2, ob2) = finish(p+1, a, b, ca*10+int(a[p]), cb*10+int(a[p])+1)
            if int(a[p]) > 0:
                (oa3, ob3) = finish(p+1, a, b, ca*10+int(a[p]), cb*10+int(a[p])-1)
            opts = [(abs(oa1-ob1), oa1, ob1), (abs(oa2-ob2), oa2, ob2), (abs(oa3-ob3), oa3, ob3)]
            opts.sort()
            return opts[0][1:]
    else: #a[p] == '?'
        if b[p] != '?':
            (oa1, ob1) = dfs(p+1, a, b, ca*10+int(b[p]), cb*10+int(b[p]))
            (oa2, ob2) = (1e100, 0)
            (oa3, ob3) = (1e100, 0)
            if int(b[p]) < 9:
                (oa2, ob2) = finish(p+1, a, b, ca*10+int(b[p])+1, cb*10+int(b[p]))
            if int(b[p]) > 0:
                (oa3, ob3) = finish(p+1, a, b, ca*10+int(b[p])-1, cb*10+int(b[p]))
            opts = [(abs(oa1-ob1), oa1, ob1), (abs(oa2-ob2), oa2, ob2), (abs(oa3-ob3), oa3, ob3)]
            opts.sort()
            return opts[0][1:]
        else: #both == '?'
            (oa1, ob1) = dfs(p+1, a, b, ca*10, cb*10)
            (oa2, ob2) = finish(p+1, a, b, ca*10, cb*10+1)
            (oa3, ob3) = finish(p+1, a, b, ca*10+1, cb*10)
            opts = [(abs(oa1-ob1), oa1, ob1), (abs(oa2-ob2), oa2, ob2), (abs(oa3-ob3), oa3, ob3)]
            opts.sort()
            return opts[0][1:]

f = open('B-small-attempt0.in', 'r')
outf = open('B-small-attempt0.out','w')
inp = f.read().split("\n")
f.close()

T = int(inp[0])

for itr in range(1, T+1):
    a = inp[itr].split()[0]
    b = inp[itr].split()[1]

    (outa, outb) = dfs(0, a, b, 0, 0)
    
    outf.write("Case #%d: %s %s\n" % (itr, "0"*(len(a)-len(str(outa)))+str(outa), "0"*(len(b)-len(str(outb)))+str(outb)))
outf.close()
