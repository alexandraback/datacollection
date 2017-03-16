import sys

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for i in xrange(cases):
    ern = stdin.pop(0).split(' ')
    n = int(ern.pop())
    r = int(ern.pop())
    e = int(ern.pop())
    c = e
    g = 0
    v = stdin.pop(0).split(' ')
    for j in xrange(len(v)):
        v[j] = int(v[j])
    if e <= r:
        for j in v:
            g += c*j
    else:
        for j in xrange(len(v)):
            w = v[0]
            k = 1
            if w == max(v):
                g += c*w
                c = 0
            else:
                while w > v[k]:
                    if k*r > c:
                        break
                    else:
                        k += 1
                g += k*r*w
                c -= k*r
            v.pop(0)
            c += r
            if c > e:
                c = e
    print "Case #"+str(i+1)+": "+str(g)
