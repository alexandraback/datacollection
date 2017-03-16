from fractions import *

def check(s0, s):
    cnt = 0
    t0 = Fraction(360 - s0,  s)
    for i in a:
        d1 = Fraction(i[0])
        s1 = Fraction(360, i[1])
        if s == s1:
            continue
        elif s > s1:
            if s0 > d1:
                continue
            dd = d1 - s0
            ds = s - s1
            t1 = dd / ds
            if t1 <= t0:
                cnt += 1
        else:
            dd = (s0 - d1) % 360
            if dd == 0:
                dd = 360
            ds = s1 - s
            t1 = dd / ds
            if t1 <= t0:
                cnt += 1
                nd = t1 * s
                left = 360 - nd
                t1 = 360 / ds
                cnt += left // t1
    return cnt

fin = open("c-small1.in", "r")
fout = open("c-small1.txt", "w")

t = int(fin.readline())
for ii in range(1, t + 1):
    n = int(fin.readline())
    a = []
    for i in range(n):
        d, h, m = map(int, fin.readline().split())
        for j in range(h):
            a.append((d, m + j))
    a.sort()
    res = float('inf')
    if a[0][0] < a[1][0]:
        res = min(res, check(a[0][0], Fraction(360, a[0][1])))
    else:
        res = min(res, check(a[0][0], Fraction(360, a[1][1])))
        res = min(res, check(a[0][0], Fraction(360, a[0][1])))
    print('Case #', ii, ': ', res, sep='', file=fout)

fin.close()
fout.close()
