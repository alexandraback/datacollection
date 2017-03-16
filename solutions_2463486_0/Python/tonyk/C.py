##fi = open('sample.in', 'r')
##fo = open('sample.out', 'w')
fi = open('C-small-attempt0.in', 'r')
fo = open('C-small-attempt0.out', 'w')
##fi = open('C-large.in', 'r')
##fo = open('C-large.out', 'w')

pows = []
roots = [[1, 1, 1], [2, 1, 4], [3, 1, 9]]

pot = 1
pows.append(pot)
for i in xrange(2, 51):
    pot *= 10
    pows.append(pot)
    
    sw1 = pot + 1
    sw2 = sw1 * 2

    nr = len(roots)
    roots.append([sw1, i, 2])
    for j in xrange(nr):
        r = roots[j]
        if (i % 2) == (r[1] % 2):
            if r[2] + 2 < 10:
                new = sw1 + r[0] * pows[(i - r[1]) / 2]
                roots.append([new, i, r[2] + 2])
                
    roots.append([sw2, i, 8])
    for j in xrange(nr):
        r = roots[j]
        if (i % 2) == (r[1] % 2):
            if r[2] + 8 < 10:
                new = sw2 + r[0] * pows[(i - r[1]) / 2]
                roots.append([new, i, r[2] + 8])

##for x in roots:
##    print x[0]

fas = [r[0] * r[0] for r in roots]
##for i in xrange(len(fas) - 1):
##    if fas[i] > fas[i+1]:
##        print 'ERROR'

##print len(fas)
##for x in fas:
##    print x

tc = int(fi.readline())
for i in xrange(tc):
    nums = fi.readline().split()
    a, b = int(nums[0]), int(nums[1])

    res = 0
    j = 0
    while fas[j] <= b:
        if fas[j] >= a:
            res += 1
        j += 1
        if j >= len(fas):
            break
    
    fo.write('Case #' + str(i+1) + ': ' + str(res) + '\n')

        
fi.close()
fo.close()
