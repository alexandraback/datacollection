import os
import re
import math
from collections import deque
import heapq
import time


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def func(p, q):
    m = gcd(p, q)
    p, q = int(p / m), int(q / m)
    if int(math.pow(2, int(math.log2(q)))) != q:
        return -1
    ans = 0
    while (q >> 1) > 0:
        if p >= q:
            break
        else:
            ans += 1
        q = (q >> 1)
    return ans

# def function():
#     return False


def main(fin, fout):
    start = time.clock()
    fin = open(fin, 'r')
    fout = open(fout, 'w')
    k = int(fin.readline())
    for i in range(k):
        p, q = [int(w) for w in fin.readline().split('/')]
        ans = func(p, q)

        fout.write('Case #' + str(i + 1) + ': ')
        if ans == -1:
            fout.write('impossible' + '\n')
        else:
            fout.write(str(ans) + '\n')

        if i % 10 == 9:
            print('Case #' + str(i + 1) + '/' + str(k) + ' ' + 'finished, %.3f' % (time.clock() - start) + ' sec taken')

    fin.close()
    fout.close()
    pass

if __name__ == '__main__':
    problem = 'A'
    _fin = problem + '/A-large.in'
    _fout = _fin[:-2] + 'out'
    main(_fin, _fout)
