import sys
from copy import copy
from fractions import Fraction


def solve(d, m):
    if m[0] == m[1]:
        return 0

    if m[0] > m[1]:
        if (360 - d[0])*(m[0] - m[1]) < (360 - d[1] + d[0])*m[1]:
            return 0
        else:
            return 1
    else:
        if (d[1] - d[0])*m[1] >= (360 - d[0])*(m[1] - m[0]):
            return 0
        else:
            nd = [d[0] + Fraction((d[1] - d[0])*m[1], (m[1] - m[0])),
                  d[0] + Fraction((d[1] - d[0])*m[1], (m[1] - m[0]))]
            m[0], m[1] = m[1], m[0]
            return solve(nd, m)


tests = sys.stdin.readlines()
n_tests = int(tests[0])

start = 1
for test_idx in range(1, n_tests+1):
    count = int(tests[start])
    if count == 1:        
        vals = map(int, tests[start + 1].split())
        d = [copy(vals[0]), copy(vals[0])]
        m = [copy(vals[2]), vals[2] + 1]
    elif count == 2:
        vals1 = map(int, tests[start + 1].split())
        vals2 = map(int, tests[start + 2].split())
        d = [vals1[0], vals2[0]]
        m = [vals1[2], vals2[2]]
    else:
        print('FAIL')
        start += (count + 1)
        continue
    start += (count + 1)

    if d[0] > d[1]:
        d[0], d[1] = d[1], d[0]
        m[0], m[1] = m[1], m[0]
    if d[0] == d[1] and m[0] < m[1]:
        m[0], m[1] = m[1], m[0]

    print('Case #{}: {}'.format(test_idx, solve(d, m)))
    
