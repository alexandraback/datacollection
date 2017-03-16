#!/usr/bin/env python2

f = open('i', 'r')

n = int(f.readline()[:-1])

for i in range(n):
    s = f.readline()[:-1]
    ary = s.split(' ')
    A = int(ary[0])
    B = int(ary[1])
    ps = []
    s = f.readline()[:-1]
    ary = s.split(' ')
    for j in range(A):
        ps.append(float(ary[j]))
    
    ans = 1<<30
    pa = 0
    for bc in range(A, -1, -1):
        if bc != A:
            if pa == 0:
                pa = 1.0
            pa *= ps[A-bc-1]
        co = (bc + B-(A-bc)+1)
        wr = bc + B + B - (A - bc)+ 2
        if bc == A:
            wr = bc + B + 1
        tr = pa * co + (1-pa) * wr
        #print pa, co, wr, tr
        if tr < ans:
            ans = tr
        if bc == 0:
            if A == B:
                tr = 1 * pa + (1-pa) * (2 + B)
            else:
                tr = 2 + B
            if tr < ans:
                ans = tr

    print 'Case #%d: %.6f' % (i+1, ans)

