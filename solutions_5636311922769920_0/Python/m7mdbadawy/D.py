fin = open("D-small-attempt0.in","r")
fout = open("out.txt","w")

t = int(fin.readline())

def flip(s):
    t = ["+" if l=="-" else "-" for l in s]
    return "".join(t)

def solve(k,c):
    p = [i for i in xrange(k)]
    t = [x for x in p]
    for i in xrange(c-1):
        pos = 0
        for j in xrange(1,len(p)):
            pos += (p[j]-p[j-1])*k
            t[j] = pos + j
        p = [x for x in t]
    for i in xrange(len(p)):
        p[i] += 1
    return p


for i in xrange(t):
    k,c,s = map(int,fin.readline().strip().split())
    fout.write("Case #%d: "%(i+1))
    if k == s:
        fout.write(" ".join(map(str,solve(k,c))))
        fout.write("\n")
    else:
        fout.write("IMPOSSIBLE\n")

fin.close()
fout.close()
