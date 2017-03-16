#!/usr/local/bin/pypy

import sys, decimal as dec, collections as coll, itertools as itt, fractions as frac, math

if len(sys.argv) >= 2 and sys.argv[1] == 'debug':
    DEBUG = True
else:
    DEBUG = False


INF = 10**19


def solve(i, smallerA, resa, resb):
    if i == len(a):
        return (abs(int(''.join(resa)) - int(''.join(resb))), resa, resb)

    if smallerA is None:
        if a[i] != '?' and b[i] != '?':
            resa.append(a[i])
            resb.append(b[i])

            if a[i] != b[i]:
                smallerA = a[i] < b[i]

            return solve(i+1, smallerA, resa, resb)



        if a[i] == b[i] == '?':
            return min(
                solve(i+1, None, resa[:] + ['0'], resb[:] + ['0']),
                solve(i+1, True, resa[:] + ['0'], resb[:] + ['1']),
                solve(i+1, False, resa[:] + ['1'], resb[:] + ['0']),
            )
        elif a[i] == '?':
            tmp = (INF, [], [])

            if b[i] > '0':
                tmp = min(tmp, solve(i+1, True, resa[:] + [str(int(b[i])-1)], resb[:] + [b[i]]))

            tmp = min(tmp, solve(i+1, None, resa[:] + [b[i]], resb[:] + [b[i]]))

            if b[i] < '9':
                tmp = min(tmp, solve(i+1, False, resa[:] + [str(int(b[i])+1)], resb[:] + [b[i]]))

            return tmp

        elif b[i] == '?':
            tmp = (INF, [], [])

            if a[i] > '0':
                tmp = min(tmp, solve(i+1, False, resa[:] + [a[i]], resb[:] + [str(int(a[i])-1)]))

            tmp = min(tmp, solve(i+1, None, resa[:] + [a[i]], resb[:] + [a[i]]))

            if a[i] < '9':
                tmp = min(tmp, solve(i+1, True, resa[:] + [a[i]], resb[:] + [str(int(a[i])+1)]))

            return tmp

    if smallerA:
        if a[i] == '?':
            resa.append('9')
        else:
            resa.append(a[i])

        if b[i] == '?':
            resb.append('0')
        else:
            resb.append(b[i])
    else:
        if a[i] == '?':
            resa.append('0')
        else:
            resa.append(a[i])

        if b[i] == '?':
            resb.append('9')
        else:
            resb.append(b[i])

    return solve(i+1, smallerA, resa, resb)




_T = int(raw_input())
_tt = max(_T/10, 1)

for _cc in xrange(_T):
    print 'Case #{}:'.format(_cc+1),
    if _cc % _tt == 0:
        print >>sys.stderr, 'Solving: ', (_cc+1)*100/_T, '%'

    a, b = raw_input().split()

    _, resa, resb = solve(0, None, [], [])

    print ''.join(resa), ''.join(resb)

