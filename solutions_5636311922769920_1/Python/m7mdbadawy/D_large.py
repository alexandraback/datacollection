fin = open("D-large.in","r")
fout = open("out.txt","w")

t = int(fin.readline())


def solve(k,c):
    p = [i for i in xrange(k)]
    t = [x for x in p]
    for i in xrange(1,c):
        if (len(p) > 1):
            p.pop(0)
        t = []
        for e in p:
            t.append((e-1)*(k**(i))+e)
    for i in xrange(len(t)):
        t[i] += 1
    return t


for i in xrange(t):
    k,c,s = map(int,fin.readline().strip().split())
    fout.write("Case #%d: "%(i+1))
    p = solve(k,c)
    if len(p) <= s:
        fout.write(" ".join(map(str,p)))
        fout.write("\n")
    else:
        fout.write("IMPOSSIBLE\n")

fin.close()
fout.close()
