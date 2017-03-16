import math
def gcd(a, b):
    while(a % b != 0):
        a, b = b, a % b
    return b


f = open("input.in")
outf = open("output.out", "w")

T = int(f.readline())
for Ti in range(T):
    r = f.readline().split("/")
    P = int(r[0])
    Q = int(r[1])
    g = gcd(Q, P)
    P /= g
    Q /= g
    if abs(2 ** int(math.log(Q, 2)) - Q) > 1e-9:
        outf.write("Case #%d: impossible\n" % (Ti + 1))
        continue

    out = 0
    c = Q
    while P < c:
        out += 1
        c /= 2

    outf.write("Case #%d: %d\n" % (Ti + 1, out))

outf.close()
f.close()