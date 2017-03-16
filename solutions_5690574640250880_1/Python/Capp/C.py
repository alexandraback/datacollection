#!/usr/bin/env python

from sys import stdin
from math import ceil

T = int(stdin.readline())

for t in range(T):
    wds = stdin.readline().split()
    R = int(wds[0])
    C = int(wds[1])
    M = int(wds[2])

    S = R * C - M
    ret = [["*"]*C for r in range(R)]
    ret[0][0] = 'c'

    if min(R, C) == 1:
        for i in range(1, S):
            if R == 1:
                ret[0][i] = '.'
            else:
                ret[i][0] = '.'
                pass
            pass
        pass

    elif S == 1:
        pass

    elif min(R, C) == 2:
        if S % 2 == 0 and S > 2:
            for i in range(S/2):
                if R == 2:
                    ret[0][i] = '.'
                    ret[1][i] = '.'
                else:
                    ret[i][0] = '.'
                    ret[i][1] = '.'
                    pass
                pass
            pass
            ret[0][0] = 'c'
        else:
            ret = None
            pass
        pass

    else:
        if S in [2, 3, 5, 7]:
            ret = None
        else:
            if M >= (R-2) * (C-2):
                ret[1][0] = '.'
                ret[1][1] = '.'
                ret[0][1] = '.'
                if S % 2 == 1: ret[2][2] = '.'
                sr = (S / 2 + 2 + 1) / 2
                sc = (S / 2 + 2 + 0) / 2
                if sr > R:
                    sc += (sr - R)
                    sr = R
                    pass
                if sc > C:
                    sr += (sc - C)
                    sc = C
                    pass
                for i in range(2, sr):
                    ret[i][0] = '.'
                    ret[i][1] = '.'
                    pass
                for i in range(2, sc):
                    ret[0][i] = '.'
                    ret[1][i] = '.'
                    pass
                pass
            else: ## M < (R-2) * (C-2)
                ret = [["."]*C for r in range(R)]
                ret[R-1][C-1] = 'c'
                r = M / (C-2)
                c = M % (C-2)
                for i in range(0, r):
                    for j in range(0, C-2):
                        ret[i][j] = '*'
                        pass
                    pass
                for j in range(0, c):
                    ret[r][j]  = '*'
                    pass
                pass
            pass
        pass

    print "Case #%d:" % (t+1)
    # print R, C, M
    # cnt = 0
    # if ret == None: continue
    # for i in ret:
    #     for j in i:
    #         if j == '*': cnt += 1
    # if M != cnt:
    #     print M, cnt, "Error"
    #     exit(1)
    if ret == None:
        print "Impossible"
    else:
        for line in ret:
            linec = ""
            for c in line: linec += c
            print linec
