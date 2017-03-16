# -*- coding:utf-8 -*-
from sys import stdin, stdout
import math, numpy, random
rd = lambda: stdin.readline()

cnt = 0
b = 0
status = []
visited = []
cycle = 0
def dfs(idx):
    global status, cnt, visited, b, cycle
    if idx == b-1:
        cnt += 1
        return

    for i, adj in enumerate(status[idx]):
        if cycle == 1:
            return
        if adj == 1:
            if visited[i] == 0:
                visited[i] = 1
                dfs(i)
                visited[i] = 0
            else:
                cycle = 1
                return


def getnpath():
    global status, cnt, visited, b, cycle
    cycle = 0
    cnt = 0
    visited = numpy.zeros(b)
    visited[0] = 1
    dfs(0)
    
    return cnt

T = map(int, rd().split())
for tc in range(T[0]):
    b, m = map(int, rd().split())
    if pow(2,b-2) < m:
        print 'Case #%d: IMPOSSIBLE' % (tc+1)
        continue

    status = numpy.zeros((b,b))
    while True:
        t = getnpath()
        #print '# path', t
        if cycle == 1 or t > m:
            # randomly 1 -> 0
            while True:
                w = numpy.where(status == 1)
                r = random.randrange(len(w[0]))
                row = w[0][r]
                col = w[1][r]
                if row != col and col != 0 and row != b-1:
                    status[row,col] = 0
                    break
        elif t < m:
            # randomly 0 -> 1
            while True:
                w = numpy.where(status == 0)
                r = random.randrange(len(w[0]))
                row = w[0][r]
                col = w[1][r]
                if row != col and col != 0 and row != b-1 and status[col,row] == 0:
                    status[row,col] = 1
                    break
        else:
            break

    print 'Case #%d: POSSIBLE' % (tc+1)
    for i in status:
        for j in i:
            stdout.write(('%d'%j))
        print ''
