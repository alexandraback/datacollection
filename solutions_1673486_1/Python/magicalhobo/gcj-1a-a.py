def calc(l, ps):
    l = int(l)
    t = len(ps) 
    r = l - t 
    p = 1 
 
    s = [] 
    s.append(l + 2) 
     
    for i in range(t): 
        b = t - i 
        s.append(p * (2 * b + r + 1) + (1 - p) * (2 * b + r + 1 + l + 1))
        p *= float(ps[i])
    
    s.append(p * (r + 1) + (1 - p) * (r + 1 + l + 1))
    
    return '{0:.{1}f}'.format(min(s), 6)

def parse(n):
    fi = open('%s.in' % n, 'r')
    c = int(fi.readline())
    r = []
    for i in range(c):
        a, b = fi.readline()[:-1].split(' ')
        c = fi.readline()[:-1].split(' ')
        r.append('Case #%s: %s\n' % (i + 1, calc(b, c)))
    print ''.join(r)
    fi.close()
    fo = open('%s.out' % n, 'w')
    fo.writelines(r)
    fo.close()

parse('A-large')
