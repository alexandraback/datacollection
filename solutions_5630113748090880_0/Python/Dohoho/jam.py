n = int(raw_input())
for ii in xrange(n):
    n2 = int(raw_input())
    m = {}
    for i2 in xrange(n2*2-1):
        for i in map(int, raw_input().split()):
            if i in m:
                m[i] += 1
            else:
                m[i] = 1
    lst = []
    for i in m:
        if m[i] & 1 == 1:
            lst.append(i)
    print "Case #%d: %s" % (ii+1, ' '.join(map(str, sorted(lst))))