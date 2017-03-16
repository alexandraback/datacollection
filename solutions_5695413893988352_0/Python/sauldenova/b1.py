#!/usr/local/bin/python3

from __future__ import print_function

def get_value(c):
    return ord(c) - ord('0');

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
        for k in range(0, 10):
            res_c += str(k)
            if j[i] == '?':
                for l in range(0, 10):
                    res_j += str(l)
                    search_result(i + 1, c, j, res_c, res_j)
                    res_j = res_j[:-1]
            else:
                res_j += j[i]
                search_result(i + 1, c, j, res_c, res_j)
                res_j = res_j[:-1]
            res_c = res_c[:-1]
    elif j[i] == '?':
        for l in range(0, 10):
            res_j += str(l)
            res_c += c[i]
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

