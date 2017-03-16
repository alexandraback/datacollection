def solve(l):
    l = l.split(" ")
    l = [int(v) for v in l]
    #print l
    global N,M,K
    # N = 3, M = 5, K = 7
    # N(3) nums entre 2 y M(5)
    # K(7) productos de las ?? cartas
    for a in xrange(2,M+1):
        for b in xrange(2,M+1):
            for c in xrange(2,M+1):
                #print a,b,c
                yes = True
                for v in l:
                    if v == 1: continue
                    if v != a and v != b and v != c and v != a*b and v != a*c and v != b*c and v != a*b*c:
                        yes = False
                        break
                if yes:
                    return "%d%d%d" % (a,b,c)
    return "..."

prob = "c"
f = open(prob+".in","r")
d = f.read()[:-1]
f.close()
f = open(prob+".out","w")
lines = d.split("\n")
Tcount = int(lines[0])
T = 1
i = 2
l = lines[1]
R,N,M,K = l.split(" ")
R,N,M,K = int(R),int(N),int(M),int(K)
print "Case #1:"
f.write("Case #1:\n")
while i < len(lines):
    line1 = lines[i]
    i += 1
    S = solve(line1)
    print S
    f.write(S + "\n")
    T += 1
    
f.close()
