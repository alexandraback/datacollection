#!/usr/bin/python

import sys
import itertools

def solve(C, J):
    #print("C = {:}, J = {:}".format(C, J))
    posJ = [1,2,3]
    posC = [1,2,3]
    for i in range(len(J)):
        if C[i] == '?' and J[i] == '?':
            posJ[i] = [0,1,9]
            posC[i] = [0,1,9]
        elif C[i] == '?':
            J[i] = int(J[i])
            posJ[i] = [J[i]]
            posC[i] = list(range(10))
            continue
            if int(J[i]) == 0 or int(J[i]) == 9:
                posC[i] = [0,1,9]
            else:
                posC[i] = [J[i]-1, J[i], J[i] + 1]
        elif J[i] == '?':
            C[i] = int(C[i])
            posC[i] = [C[i]]
            posJ[i] = list(range(10))
            continue
            if int(C[i]) == 0 or int(C[i]) == 9:
                posJ[i] = [0,1,9]
            else:
                posJ[i] = [C[i]-1, C[i], C[i] + 1]
        else:
            posJ[i] = [str(J[i])]
            posC[i] = [str(C[i])]
        #print('i = {:}, posC = {:}, posJ = {:}'.format(i, posC[i], posJ[i]))
    #print("POSSIBLE")
    posJ = posJ[:len(J)]
    posC = posC[:len(C)]
    #print(posC)
    #print(posJ)
    for i in range(len(J)):
        if isinstance(posJ[i], list):
            posJ[i] = map(str, posJ[i])
        else:
            posJ[i] = str(posJ[i])
        if isinstance(posC[i], list):
            posC[i] = map(str, posC[i])
        else:
            posC[i] = str(posC[i])
    js = [int(''.join(i)) for i in itertools.product(*posJ)]
    cs = [int(''.join(i)) for i in itertools.product(*posC)]
    #print('COMBOS')
    #print(cs)
    #print(js)

    mj = 1000
    mc = 1000
    curmin = 1000
    for j in js:
        for c in cs:
            #print('{:} - {:} = {:} '.format(c, j, abs(c-j)))
            if abs(c - j) == curmin:
                if c < mc:
                    mc = c
                    mj = j
                elif c == mc:
                    mj = min(mj, j)
            elif abs(c-j) < curmin:
                curmin = abs(c-j)
                mc = c
                mj = j
                
    lj = len(str(mj))
    lc = len(str(mc))
    if lj < len(J):
        pd = '0' * (len(J) - lj)
        mj = pd + str(mj)

    if lc < len(J):
        pd = '0' * (len(C) - lc)
        mc = pd + str(mc)
    return str(mc) + ' ' + str(mj)

        

    for i in range(len(C)):
        if C[i] != '?' and J[i] != '?':
            continue
        if C[i] == '?' and J[i] == '?':
            if i == 0:
                C[i] = 0
                J[i] = 0
                continue
            nowJ = int(''.join(map(str, J[0:i])))
            nowC = int(''.join(map(str, C[0:i])))
            if nowJ > nowC: #doesn't include i.. [0:0] = empty
                C[i] = 9
                J[i] = 0
                continue
            if nowC > nowJ:
                C[i] = 0
                J[i] = 9
                continue
            if nowC == nowJ:
                C[i] = 0
                J[i] = 0
                continue

        if C[i] == '?':
            if i == 0:
                C[i] = J[i]
                continue
            nowJ = int(''.join(map(str, J[0:i])))
            nowC = int(''.join(map(str, C[0:i])))
            if nowC > nowJ:
                C[i] = 0
                continue
            if nowC < nowJ:
                C[i] = 9
                continue
            if nowC == nowJ:
                C[i] = J[i]
                continue


        if J[i] == '?':
            if i == 0:
                J[i] = C[i]
                continue
            nowJ = int(''.join(map(str, J[0:i])))
            nowC = int(''.join(map(str, C[0:i])))
            if nowJ > nowC:
                J[i] = 0
                continue
            if nowJ < nowC:
                J[i] = 9
                continue
            if nowJ == nowC:
                J[i] = C[i]
                continue
    soln = ''.join(map(str, C)) + ' ' + ''.join(map(str, J))
    return soln


with open(sys.argv[1], 'r') as f:
    cases = int(f.readline())
    for case in range(cases):
        C, J= f.readline().strip().split()
        C = list(C)
        J = list(J)
        ans = solve(C,J)
        print("Case #{:}: {:}".format(case+1, ans))
        #print('*' * 20)


