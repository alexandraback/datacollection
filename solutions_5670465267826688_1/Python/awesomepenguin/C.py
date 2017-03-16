t = int(raw_input())

order = ['1', '-1', 'i', '-i', 'j', '-j', 'k', '-k']


table = ['1   -1  i   -i  j   -j  k   -k',
'-1  1   -i  i   -j  j   -k  k',
'i   -i  -1  1   k   -k  -j  j',
'-i  i   1   -1  -k  k   j   -j',
'j   -j  -k  k   -1  1   i   -i',
'-j  j   k   -k  1   -1  -i  i',
'k   -k  j   -j  -i  i   -1  1',
'-k  k   -j  j   i   -i  1   -1']

mult = {}

for i, s in enumerate(table):
    mult[order[i]] = {}
    row = s.split()
    for j, elem in enumerate(row):
        mult[order[i]][order[j]] = elem


for qq in xrange(1, t+1):

    _, y = map(int, raw_input().split())
    seq = raw_input()

    x = y % 24
    if y >= 24: x += 24

    seq = seq*x

    first = True
    v = [['1'], ['-i'], ['-k']]

    for e in seq:
        for i in xrange(3):
            v[i].append(mult[v[i][-1]][e])
        if first:
            first = False
            for i in xrange(3):
                v[i].pop(0)

#    print v

    l = len(seq)
    
    if v[2][l-1] != 'k':
        print 'Case #%d: NO' % qq
        continue

    done = False
    for i in xrange(l):
        if done: break
        if v[0][i] != 'i': continue
        for j in xrange(i+1, l):
            if done: break
            if v[1][j] == 'j': done = True

    if done: print 'Case #%d: YES' % qq
    else: print 'Case #%d: NO' % qq
