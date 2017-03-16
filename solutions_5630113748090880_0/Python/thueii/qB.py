import sys

def g(x, c):
    if len(x) == 0:
        return c
    else:
        if c >= x[0]:
            return c + x
        else:
            return x + c        

l = sys.stdin.readline()
m = int(l.strip())

for i in range(0, m):
    l = sys.stdin.readline().strip()
    n = int(l)
    c = {}
    for j in range(0, 2 * n - 1):
        l = sys.stdin.readline().strip()
        tokens = l.split(" ")
        for x in tokens:
            if int(x) not in c:
                c[int(x)] = 0
            c[int(x)] += 1
    z = []
    for x in c.keys():
        if c[x] % 2 == 1:
            z.append(x)
    z = sorted(z)
    print("Case #%d: %s" % (i + 1, " ".join([str(x) for x in z])))


