__author__ = 'cni'

import numpy as np
from math import sqrt

def calp(data, x, y, lx, ly):
    count = 0
    points = [(x - 1, y), (x, y - 1), (x, y + 1), (x + 1, y), (x - 1, y - 1), (x + 1, y + 1),(x - 1, y + 1), (x + 1, y - 1)]
    for px, py in points:
        if px > -1 and py > -1 and px < lx and py < ly:
            if data[px][py] == 1:
                count += 1
    return count

def test(data, x, y, lx, ly):
    count = 1
    data[x][y] = -1
    if calp(data, x, y, lx, ly) == 0:
        points = [(x - 1, y), (x, y - 1), (x, y + 1), (x + 1, y), (x - 1, y - 1), (x + 1, y + 1),(x - 1, y + 1), (x + 1, y - 1)]
        for px, py in points:
            if px > -1 and py > -1 and px < lx and py < ly:
                if calp(data, px, py, lx, ly) == 0 and data[px][py] != -1:
                    count += test(data, px, py, lx, ly)
                elif data[px][py] == 0:
                    count += 1
                    data[px][py] = -1
    return count

def cal(R, C, T):
    origT = T
    tran = False
    if R < C:
        t = R
        R = C
        C = t
        tran = True
    data = np.zeros((R, C), dtype=int)

    blank = R * C - T
    t = int(sqrt(blank))
    st = int(sqrt(origT))

    if st ** 2 == origT and R - st > 1 and C - st > 1:
        for i in xrange(st):
            for j in xrange(st):
                data[i][j] = 1
    elif t * t != blank or R < t or C < t:
        if R >= C:
            l = T / C
            if R - l == 1 and l != 0:
                l -= 1
            T -= l * C

            for i in xrange(0, l):
                data[i] = np.ones((1, C), dtype=int)
            remain = R - l

            new_l = T / remain
            for i in xrange(l, R):
                for j in xrange(0, new_l):
                    data[i][j] = 1
            remain = T % remain

            if (R - l - remain) > 1:
                for i in xrange(l, l + remain):
                    data[i][new_l] = 1
            else:
                for i in xrange(0, remain):
                    data[l][new_l + i] = 1
    else:
        for i in xrange(0, R - t):
            for j in xrange(C):
                data[i][j] = 1
        for j in xrange(0, C - t):
            for i in xrange(R):
                data[i][j] = 1
    if tran:
        data = np.transpose(data)
        t = R
        R = C
        C = t
    veri = test(data, R-1, C-1, R, C)

    if veri != R * C - origT:
        #print 'Impossible'

        print R, C, origT
        print data
        return 'Impossible\n'
    else:
        res = []
        for i in xrange(R):
            for j in xrange(C):
               if data[i][j] != 1:
                   res.append('.')
               else:
                   res.append('*')
            res.append('\n')
        res[-2] = 'c'
        return ''.join(res)


f = open('D:/sub-5.in')
lines = f.readlines()
f.close()

case_num = int(lines[0])

f = open('D:/out.txt', 'w')

for i in xrange(1, case_num + 1):
    R, C, M = tuple([int(j) for j in lines[i].split()])
    res = cal(R, C, M)
    f.write('Case #%d:\n%s' % (i, res))

f.close()
