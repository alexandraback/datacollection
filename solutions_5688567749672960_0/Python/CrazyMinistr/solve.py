# -*- coding: utf-8 -*-
fin = open("in", "r")
fout = open("out", "w")


def pre_calc(n):
    f = [2000000000] * (n + 2)
    f[1] = 1
    for i in range(1, n + 1):
        f[i + 1] = min(f[i + 1], f[i] + 1)
        tmp = str(i)
        tmp = tmp[::-1]
        while tmp[0] == '0':
            tmp = tmp[1:]
        tmp = int(tmp)
        if n >= tmp > i:
            f[tmp] = min(f[tmp], f[i] + 1)
    return f

d = pre_calc(1000001)
print d

t = int(fin.readline())
for tt in range(t):
    N = int(fin.readline())
    fout.write("Case #%d: %d\n" % (tt + 1, d[N]))
