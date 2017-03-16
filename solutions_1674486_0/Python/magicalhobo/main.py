def trace(t, i, h):
    if i in h:
        return True
    h.append(i)
    n = t[i]
    r = False
    if len(n) > 0:
        for v in n:
            r = trace(t, v, h)
            if r:
                break
    return r

def calc(m):
    r = 'No'
    for k, v in enumerate(m):
        if trace(m, k + 1, []):
            r = 'Yes'
    return r

def parse(name):
    fi = open('%s.in' % name, 'r')
    c = int(fi.readline())
    r = []
    for i in range(c):
        m = {}
        n = int(fi.readline())
        for j in range(n):
            a = fi.readline()[:-1].split(' ')
            for k in range(len(a)):
                a[k] = int(a[k])
            m[j + 1] = a[1:]
        r.append('Case #%s: %s\n' % (i + 1, calc(m)))
    print ''.join(r)
    fi.close()
    fo = open('%s.out' % name, 'w')
    fo.writelines(r)
    fo.close()

parse('A-small-attempt1')
