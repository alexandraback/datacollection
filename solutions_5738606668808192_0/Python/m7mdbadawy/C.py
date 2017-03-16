import math
fin = open("C-small-attempt0.in","r")
fout = open("out.txt","w")

t = int(fin.readline())
n,j = map(int,fin.readline().strip().split())
MAX = 10**2
d = {}

def convert(num,base):
    ans = 0
    p = 1
    for i in xrange(33):
        if (num&(1<<i) > 0):
            ans += p
        p*=base
    return ans

def test(s):
    p = []
    for i in xrange(2,11):
        t = convert(s,i)
        for j in xrange(2,min(MAX+1,int(math.sqrt(t))+1)):
            if t%j == 0:
                p.append(j)
                break
        if len(p) <= (i-2):
            break
    if (len(p) < 9): return []
    return p
        

def solve(s,start):
    if(len(d) >= j) : return
    if(start==n-1):
        t = test(s)
        if (t != []): d[s] = t
        return
    solve(s,start+1)
    solve(s|(1<<start),start+1)

solve((1<<(n-1))+1,1)
fout.write("Case #1:\n")
for x in d:
    fout.write(bin(x)[2:] + " ")
    fout.write(" ".join(map(str,d[x])) + "\n")
fin.close()
fout.close()
