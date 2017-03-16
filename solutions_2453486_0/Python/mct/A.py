# -*- coding:utf-8 -*-

import sys

output = ["X won", "O won", "Draw", "Game has not completed"]
X = [set(list('XXXT')), set(list('XXXX'))]
O = [set(list('OOOO')), set(list('OOOT'))]


def judge(a):
    if a in X:
        return output[0]
    elif a in O:
        return output[1]
    else:
        return None

def solve(f):
    # row
    for i in range(4):
        a = set([f[i], f[i+4], f[i+8], f[i+12]])
        if judge(a):
            return judge(a)
    for i in range(0, 16, 4):
        a = set(f[i:i+4])
        if judge(a):
            return judge(a)
    a = set([f[0], f[5], f[10], f[15]])
    if judge(a):
        return judge(a)
    a = set([f[3], f[6], f[9], f[12]])
    if judge(a):
        return judge(a)
    if '.' in f:
        return output[3]
    else:
        return output[2]

T = int(sys.stdin.readline())
for t in range(T):
    f = []
    for i in range(4):
        f += list(sys.stdin.readline()[:-1])
    sys.stdin.readline()
    res = solve(f)
    print "Case #%d: %s" % (t + 1, res)
