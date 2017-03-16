def gre(a, b):
    v1 = a[0] * b[1]
    v2 = a[1] * b[0]
    return v1 >= v2

def max_fr(a, b):
    return a if gre(a, b) else b

def mul(a, b):
    return (a[0] * b[0], a[1] * b[1])

def add(a, b):
    return (a[0] * b[1] + a[1] * b[0], a[1] * b[1])

def sub(a, b):
    return (a[0] * b[1] - a[1] * b[0], a[1] * b[1])

def solve():
    n = int(input())
    groups = [None for i in range(n)]
    for i in range(n):
        d, h, m = map(int, input().split())
        groups[i] = (d, h, m)

    if n == 1:
        return 0

    if groups[0][0] > groups[1][0]:
        groups[0], groups[1] = groups[1], groups[0]
    t1 = ((360 - groups[0][0]) * groups[0][2], 360)
    t2 = ((360 - groups[1][0]) * groups[1][2], 360)

    mt = max_fr(t1, t2)

    dst1 = mul(mt, (360, groups[0][2]))
    dst2 = mul(mt, (360, groups[1][2]))

    d1 = groups[0][0]
    d2 = groups[1][0]

    m1 = groups[0][2]
    m2 = groups[1][2]

    if m1 == m2:
        return 0
    if m1 < m2:
        return gre(sub( add(dst1, (d1, 1)), add(dst2, (d2, 1)) ), (360, 1)) 
    else:
        return gre( add(dst2, (d2, 1)), add(dst1, (d1, 1)))


for t in range(1, int(input()) + 1):
    print('Case #%d: %d' % (t, solve()))
