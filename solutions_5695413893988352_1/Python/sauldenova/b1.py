#!/usr/local/bin/python3

from __future__ import print_function

best_c = ''
best_j = ''

def search_result(i, c, j, res_c, res_j):
    if i == len(c):
        global best_c, best_j
        if best_c == '':
            best_c = res_c
            best_j = res_j
        else:
            vc, vj = int(res_c), int(res_j)
            bvc, bvj = int(best_c), int(best_j)
            if abs(vc - vj) < abs(bvc - bvj):
                best_c = res_c
                best_j = res_j
            elif abs(vc - vj) == abs(bvc - bvj):
                if vc < bvc:
                    best_c = res_c
                    best_j = res_j
                elif vc == bvc and vj < bvj:
                    best_c = res_c
                    best_j = res_j

        return

    if c[i] == '?':
        if j[i] == '?':
            for k in range(0, 2):
                if res_c > res_j:
                    res_c += '0'
                    res_j += '9'
                    search_result(i + 1, c, j, res_c, res_j)
                    res_j = res_j[:-1]
                    res_c = res_c[:-1]
                elif res_c < res_j:
                    res_c += '9'
                    res_j += '0'
                    search_result(i + 1, c, j, res_c, res_j)
                    res_j = res_j[:-1]
                    res_c = res_c[:-1]
                else:
                    for l in range(0, 2):
                        res_c += str(k)
                        res_j += str(l)
                        search_result(i + 1, c, j, res_c, res_j)
                        res_j = res_j[:-1]
                        res_c = res_c[:-1]
        else:
            if res_c > res_j:
                res_c += '0'
                res_j += j[i]
                search_result(i + 1, c, j, res_c, res_j)
                res_j = res_j[:-1]
                res_c = res_c[:-1]
            elif res_c < res_j:
                res_c += '9'
                res_j += j[i]
                search_result(i + 1, c, j, res_c, res_j)
                res_j = res_j[:-1]
                res_c = res_c[:-1]
            else:
                for k in range(max(int(j[i]) - 1, 0), min(int(j[i]) + 2, 10)):
                    res_c += str(k)
                    res_j += j[i]
                    search_result(i + 1, c, j, res_c, res_j)
                    res_j = res_j[:-1]
                    res_c = res_c[:-1]
    elif j[i] == '?':
        if res_j > res_c:
            res_c += c[i]
            res_j += '0'
            search_result(i + 1, c, j, res_c, res_j)
            res_j = res_j[:-1]
            res_c = res_c[:-1]
        elif res_j < res_c:
            res_c += c[i]
            res_j += '9'
            search_result(i + 1, c, j, res_c, res_j)
            res_j = res_j[:-1]
            res_c = res_c[:-1]
        else:
            for l in range(max(int(c[i]) - 1, 0), min(int(c[i]) + 2, 10)):
                res_c += c[i]
                res_j += str(l)
                search_result(i + 1, c, j, res_c, res_j)
                res_j = res_j[:-1]
                res_c = res_c[:-1]
    else:
        res_c += c[i]
        res_j += j[i]
        search_result(i + 1, c, j, res_c, res_j)
        res_j = res_j[:-1]
        res_c = res_c[:-1]

T = int(input())
for t in range(1, T + 1):
    print("Case #", t, ": ", sep= '', end='')
    c, j = str(input()).split(' ')
    search_result(0, c, j, '', '')
    print(best_c, best_j)
    best_c, best_j = '', ''

