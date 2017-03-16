def can(m, c):
    n, y, x = c
    h = True
    for _x in xrange(len(m[y])):
        if m[y][_x] > n:
            h = False
            break
    if h: return True
    v = True
    for _y in xrange(len(m)):
        if m[_y][x] > n:
            v = False
            break
    return v

def solve(m):
    l = []
    for i in xrange(len(m)):
        for j in xrange(len(m[0])):
            l.append((m[i][j], i, j))
    l.sort()
    for i in xrange(len(l)-1, -1, -1):
        if not can(m, l[i]):
            return "NO"
    return "YES"

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
    line = lines[i]
    raw = line.split(" ")
    raw = [int(e) for e in raw]
    n, m = raw[0], raw[1]
    M = []
    for j in xrange(n):
        line = lines[j+i+1]
        raw = line.split(" ")
        raw = [int(e) for e in raw]
        M += [raw]
    S = "Case #%d: %s" % (T, solve(M))
    print S
    f.write(S + "\n")
    i += n + 1
    T += 1
    
f.close()
