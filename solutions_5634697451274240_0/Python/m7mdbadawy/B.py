fin = open("B-small-attempt0.in","r")
fout = open("out.txt","w")

t = int(fin.readline())

def flip(s):
    t = ["+" if l=="-" else "-" for l in s]
    return "".join(t)

def solve(s):
    ans = 0
    while not(len(set(s))==1 and s[0] == "+"):
        t = len(s)-1
        while t >= 0:
            if (s[t]=='-'): break
            t -=1
        s = flip(s[:t+1])+s[t+1:]
        ans += 1
    return ans

for i in xrange(t):
    s = fin.readline().strip()
    fout.write("Case #%d: "%(i+1))
    fout.write("%d\n"%solve(s))

fin.close()
fout.close()
