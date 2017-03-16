def readInt(): return int(raw_input())
def readList(): return map(int, raw_input().split(' '))
global m
global aa, bb
t = readInt()

def solve(a, b, k, u1, u2):
    global m, aa, bb
    y = abs(int(''.join(a)) - int(''.join(b)))

    #print a, b, y
    if y < m or m == -1:
        m = y
        aa = ''.join(a)
        bb = ''.join(b)

    if k == len(a):
        return
    if u1[k] == 1 and u2[k] == 1:
        solve(a, b, k+1, u1, u2)
        return
    iu = a[k]
    ii = b[k]
    for i in xrange(10):
        if u1[k] == 0:
            a[k] = str(i)
        for j in xrange(10):
            if u2[k] == 0:
                b[k] = str(j)
            solve(a, b, k+1, u1, u2)
    a[k] = iu
    b[k] = ii

for l in xrange(t):
    global aa, bb, m
    aa = ""
    bb = ""
    m = -1
    c, j = raw_input().split(' ')
    p, q = list(c[:]), list(j[:])
    un1 = [0 for i in xrange(len(c))]
    un2 = [0 for i in xrange(len(j))]
    for i in xrange(len(c)):
        if c[i] != '?':
            un1[i] = 1
        else:
            p[i] = '0'
    for i in xrange(len(j)):
        if j[i] != '?':
            un2[i] = 1
        else:
            q[i] = '0'

    solve(p, q, 0, un1, un2)

    print "Case #%d:" % (l+1),
    print aa, bb
