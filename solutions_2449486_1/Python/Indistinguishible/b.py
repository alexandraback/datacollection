lines = open('b.in').read().split("\n")
f = open('b.out', 'w')

n = int(lines[0])
i = 1
l = 1
while i < n+1:
    res = "YES"
    a, b = [int(x) for x in lines[l].split()]
    l += 1
    lane = []
    out = []
    for j in range(a):
        lane.append([])
        m = 0
        for q in lines[l].split():
            lane[-1].append(int(q))
            m = max(m, int(q))
        l += 1
        out.append([m]*b)
    for j in range(b):
        m = 0
        for k in range(a):
            m = max(m, lane[k][j])
        for k in range(a):
            if min(m, out[k][j]) != lane[k][j]:
                res = "NO"
                break
        if res == "NO":
            break
    f.write("Case #%d: %s\n" % (i, res))
    i += 1

f.close()
