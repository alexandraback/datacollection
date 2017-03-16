import os
import re
import math
from collections import deque
import heapq
import time


def order(strs, ord, idx):
    cnt = 0
    strscpy = strs.copy()
    idxcpy = idx
    for str in strscpy:
        flag = True
        for a in list(str):
            if a in ord.keys() and ord[a] != idx:
                flag = False
        if flag is False:
            continue
        flag = True
        roremove = []
        for a in list(str):
            # if a in ord.keys() and ord[a] != idx:
            #     flag = False
            if a not in ord.keys():
                idx += 1
                ord[a] = idx
                roremove.append(a)
        strs.remove(str)
        if len(strs) == 0:
            cnt += 1
        else:
            cnt += order(strs, ord, idx)
        strs.add(str)
        idx = idxcpy
        for a in roremove:
            ord.pop(a)
    return cnt


def validstr(str):
    ord = dict()
    idx = -1
    for a in list(str):
        if a not in ord.keys():
            idx += 1
            ord[a] = idx
        if a in ord.keys() and ord[a] != idx:
            return False
    return True


def main(fin, fout):
    start = time.clock()
    fin = open(fin, 'r')
    fout = open(fout, 'w')
    k = int(fin.readline())
    for i in range(k):
        n = int(fin.readline())
        strs = fin.readline().rstrip().split()
        flag = True
        for ss in strs:
            if validstr(ss) is False:
                flag = False
        if flag is True:
            cnt = order(set(strs), dict(), -1)
        else:
            cnt = 0
        fout.write('Case #' + str(i + 1) + ': ')
        fout.write(str(cnt) + '\n')
        print(str(cnt))
        if i % 10 == 9:
            print('Case #' + str(i + 1) + '/' + str(k) + ' ' + 'finished, %.3f' % (time.clock() - start) + ' sec taken')

    fin.close()
    fout.close()
    pass

if __name__ == '__main__':
    problem = 'B'
    _fin = problem + '/B-small-attempt3.in'
    _fout = _fin[:-2] + 'out'
    main(_fin, _fout)
