t = int(raw_input())

def la(c, s):
    r = []
    for i in s:
        r.append(c + i)
    return r

def gen(w, i):
    if i < len(w):
        if (w[i] == '?'):
            r = gen(w, i + 1)
            e = []
            for i in range(10):
                e += la(str(i), r)
            return e
        else:
            return la(w[i], gen(w, i + 1))
    return [""]

for test in range(t):
    print "Case #" + str(test + 1) + ":", 
    w1, w2 = raw_input().split(' ')
    l1 = gen(w1, 0)
    l2 = gen(w2, 0)
    mn = 10000000
    mnr = 0, 0
    for i in l1:
        for j in l2:
            r = abs(int(i) - int(j))
            if r < mn:
                mn = r
                mnr = (i, j)
    print mnr[0], mnr[1]
