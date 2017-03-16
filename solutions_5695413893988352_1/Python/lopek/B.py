#!/usr/bin/python
from pprint import pprint

def better(res1, res2):
    d1 = abs(int(res1[0]) - int(res1[1]))
    d2 = abs(int(res2[0]) - int(res2[1]))
    if d1 != d2:
        return res1 if d1 < d2 else res2

    if int(res1[0]) != int(res2[0]):
        return res1 if int(res1[0]) < int(res2[0]) else res2
    
    return res1 if int(res1[1]) < int(res2[1]) else res2

def solve(C, J, mode):
    if not C:
        return ['', '']

    if C[0] != '?' and J[0] != '?':
        if mode == 0 and C[0] != J[0]:
            mode = 1 if C[0] > J[0] else -1
        res = solve(C[1:], J[1:], mode)
        return [C[0] + res[0], J[0] + res[1]]

    if C[0] == '?' and J[0] == '?':
        if mode != 0:
            res = solve(C[1:], J[1:], mode)
            res[0] = ('0' if mode == 1 else '9') + res[0]
            res[1] = ('0' if mode == -1 else '9') + res[1]
            return res

        res0 = solve(C[1:], J[1:], 0)
        resC = solve(C[1:], J[1:], 1)
        resJ = solve(C[1:], J[1:], -1)
        res0[0] = '0' + res0[0]
        res0[1] = '0' + res0[1]
        resC[0] = '1' + resC[0]
        resC[1] = '0' + resC[1]
        resJ[0] = '0' + resJ[0]
        resJ[1] = '1' + resJ[1]
        return better(res0, better(resC, resJ))

    if J[0] == '?':
        res = solve(J, C, -mode)
        return [res[1], res[0]]

    # C[0] == '?'
    # J[0] != '?'
    if mode != 0:
        res = solve(C[1:], J[1:], mode)
        cpref = '0' if mode == 1 else '9'
        return [cpref + res[0], J[0] + res[1]]

    # C[0] == '?'
    # J[0] != '?'
    # mode == 0
    res = solve(C[1:], J[1:], 0)
    res[0] = J[0] + res[0]
    res[1] = J[0] + res[1]

    if J[0] != '9':
        resC = solve(C[1:], J[1:], 1)
        resC[0] = chr(ord(J[0]) + 1) + resC[0]
        resC[1] = J[0] + resC[1]
        res = better(res, resC)

    if J[0] != '0':
        resJ = solve(C[1:], J[1:], -1)
        resJ[0] = chr(ord(J[0]) - 1) + resJ[0]
        resJ[1] = J[0] + resJ[1]
        res = better(res, resJ)

    return res

T = int(raw_input())
for t in xrange(1, T + 1):
    inp = raw_input().split()
    res = solve(inp[0], inp[1], 0)
    print("Case #%d: %s %s" % (t, res[0], res[1]))
