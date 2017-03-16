def paintRC(r, n):
    return 2*n*r + n + 2*(n*(n-1))
def solve(m):
    r, t = m.split(" ")
    r, t = int(r), int(t)
    d = 1
    while paintRC(r, d) <= t:
        d *= 2
    i = 0
    m = (d+i)/2
    _m = m-1
    while True:
        if m == _m: return m
        _m = m
        #print i, m, d
        p = paintRC(r, m)
        if p < t: i = m
        elif p > t: d = m
        else: return m
        m = (d+i)/2
    return m

prob = "a"
f = open(prob+".in","r")
d = f.read()[:-1]
f.close()
f = open(prob+".out","w")
ms = "\n".join(d.split("\n")[1:]).split("\n")
T = 1
for m in ms:
    S = "Case #%d: %s" % (T, solve(m))
    print S
    f.write(S + "\n")
    T += 1
f.close()
