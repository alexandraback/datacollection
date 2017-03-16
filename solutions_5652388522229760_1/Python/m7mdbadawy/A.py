fin = open("A-large.in","r")
fout = open("out.txt","w")

t = int(fin.readline())

def solve(n):
    s = set(str(n))
    i = 2
    t = 1
    while len(s) < 10:
        t = n*i
        s = set(str(t)) | s
        i+=1
    return t

for i in xrange(t):
    n = int(fin.readline())
    fout.write("Case #%d: "%(i+1))
    if n == 0:
        fout.write("INSOMNIA\n")
    else:
        fout.write("%d\n"%solve(n))

fin.close()
fout.close()
