#!/usr/local/bin/pypy

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math

if len(sys.argv) >= 2 and sys.argv[1] == 'debug':
    DEBUG = True
else:
    DEBUG = False




_T = int(raw_input())
_tt = max(_T/10, 1)

for _cc in xrange(_T):
    print 'Case #{}:'.format(_cc+1),
    if _cc % _tt == 0:
        print >>sys.stderr, 'Solving: ', (_cc+1)*100/_T, '%'

    S = raw_input()

    res = []


    for i in S:
        if len(res) == 0:
            res.append( i )
        else:
            if i > res[0]:
                res.insert(0, i)
            elif i == res[0]:
                t = res[0]
                j = 0
                while j < len(res) and t == res[j]:
                    j += 1

                if j < len(res) and i > res[j]:
                    res.insert(0, i)
                else:
                    res.append( i )
            else:
                res.append( i )


    print ''.join(res)


