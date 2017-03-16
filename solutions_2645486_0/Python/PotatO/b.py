def b(e, r, v):
    total = 0
    m = [e]*len(v)
    l = [0]*len(v)
    print l,m
    for i in range(len(v)):
        ind = v.index(max(v))
        use = m[ind]-l[ind]
        total += v[ind]*use
        j = ind-1
        while j >= 0:
            new = l[ind]+use-(ind-j)*r
            if new <= l[j]:
                break
            l[j] = new
            j -= 1
        j = ind+1
        while j < len(v):
            new = (j-ind)*r
            if m[j] <= new:
                break
            m[j] = new
            j += 1
        for j in range(len(v)):
            if l[j] == m[j]:
                v[j] = 0
        v[ind] = 0
        m[ind] = 0
        l[ind] = 0
        print l,m
    print ' '
    return total

if __name__ == '__main__':
    f = open('b-small.in')
    o = open('b-small.out', 'w')
    n = int(f.readline())
    for i in range(n):
        e, r, q = [int(c) for c in f.readline().split(' ')]
        v = [int(c) for c in f.readline().split(' ')]
        o.write('Case #%d: %s\n' % (i+1, b(e, r, v)))
    o.close()
    f.close()

