import sys
fin = open("B-small-attempt0.in","r")
fout = open("out2","w")
inp = fin.readline
out = fout.write
t = int(inp())
for cases in xrange(1,t+1):
    a,b,k = map(int,inp().split())
    cnt = 0
    for i in xrange(0,a):
        for j in xrange(0,b):
            if i&j < k:
                cnt+=1
    out("Case #"+str(cases)+": "+str(cnt)+"\n")
fin.close()
fout.close()
