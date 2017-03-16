E,R,v = 0,0,[]
def bt(i, c, o = []):
    if len(o) >=6 and o[-1][1] == 5 and o[-2][1] == 5 and o[-3][1] == 5 and o[-4][1] == 5 and o[-5][1] == 5 and o[-6][1] == 5:
        print o
    if i == len(v): return 0
    G = 0
    for j in xrange(c+1):
        G = max(G, bt(i+1, min(E,c-j+R), o + [(i,j)])+(v[i]*j))
    return G
def solve(l1, l2):
    global E,R,v
    E,R,N = l1.split(" ")
    E=int(E)
    R=int(R)
    v = l2.split(" ")
    v = [int(a) for a in v]
    if R >= E: return E*sum(v)
    return bt(0,E)

prob = "b"
f = open(prob+".in","r")
d = f.read()[:-1]
f.close()
f = open(prob+".out","w")
lines = d.split("\n")
Tcount = int(lines[0])
T = 1
i = 1
while i < len(lines):
    line1 = lines[i]
    line2 = lines[i+1]
    i += 2
    S = "Case #%d: %s" % (T, solve(line1, line2))
    print S
    f.write(S + "\n")
    T += 1
    
f.close()
