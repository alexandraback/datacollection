lines = open('a.in').read().split("\n")
f = open('a.out', 'w')

def sqrt(n, appr):
    appr = long(appr)
    if appr**2 <= n:
        while appr**2 <= n:
            appr += 1
        return appr-1
    while appr**2 > n:
        appr -= 1
    return appr

n = int(lines[0])
for i in range(1, n+1):
    r, t = ([long(x) for x in lines[i].split()])
    res = int((1-2*r+sqrt((2*r-1)**2 + 8*t,((2*r-1)**2 + 8*t)**0.5))/4)
    f.write("Case #%d: %s\n" % (i, res))

f.close()
