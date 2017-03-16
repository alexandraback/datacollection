#!/usr/bin/python
import os, sys

fn = sys.stdin

total = int(fn.readline())

def printRes(case, res, turned):
    pr = ['.', '*']
    print "Case #%d:" % (case)
    if type(res) != list:
        print "Impossible"
    else:
        if turned:
            for i in range(0, len(res[0])):
                for j in range(0, len(res)):
                    if i == 0 and j == 0:
                        sys.stdout.write('c')
                    else:
                        sys.stdout.write(pr[res[j][i]])
                print ''
        else:
            for i in range(0, len(res)):
                for j in range(0, len(res[0])):
                    if i == 0 and j == 0:
                        sys.stdout.write('c')
                    else:
                        sys.stdout.write(pr[res[i][j]])
                print ''


for case in range(1, total + 1):
    tmp = fn.readline().split()
    n = int(tmp[0])
    m = int(tmp[1])
    k = int(tmp[2])
    t = n * m - k
    turned = 0
    if n > m:
        tmp = n
        n = m
        m = tmp
        turned = 1
    imp = str(n) + ' ' + str(m) + ' ' + str(k)
    res = []
    for i in range(0, n):
        res.append([])
        for j in range(0, m):
            res[i].append(0)
    if n == 1:
        for j in range(m - k, m):
            res[0][j] = 1
        printRes(case, res, turned)
    elif t == 1:
        for i in range(0, n):
            for j in range(0, m):
                res[i][j] = 1
        res[0][0] = 0
        printRes(case, res, turned)
    elif n == 2:
        if k % 2 != 0 or t == 2:
            printRes(case, imp, turned)
            continue
        for j in range(m - k / 2, m):
            res[0][j] = 1
            res[1][j] = 1
        printRes(case, res, turned)
    else:
        def search(res, i, k, mm):
            global m
            if k == 0:
                return 1
            if mm * (i + 1) < k:
                return 0
            if i == 1:
                if k % 2 == 1:
                    return 0
                if k / 2 > mm:
                    return 0
                if k / 2 == m - 1:
                    return 0
                for tmp in range(1, k / 2 + 1):
                    res[0][m - tmp] = 1
                    res[1][m - tmp] = 1
                return 1
            if k < mm:
                mm = k
            for tmp in range(0, m - mm):
                res[i][tmp] = 0
            for tmp in range(m - mm, m):
                res[i][tmp] = 1
            trylist = range(1, mm + 1)
            trylist.reverse()
            for tmp in trylist:
                if tmp + 1 != m:        
                    if search(res, i - 1, k - tmp, tmp) == 1:
                        return 1
                res[i][m - tmp] = 0
            return 0
        s = search(res, n - 1, k, m)
        if s == 1:
            printRes(case, res, turned)
        else:
            printRes(case, imp, turned)
