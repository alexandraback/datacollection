#coding: 1251
#####################################################

from __future__ import division

import os
import sys
import operator
import string
import re
import time

from os.path import splitext
from copy import copy

from math import *
from operator import *
from collections import *
from itertools import *
from functools import *

#####################################################

try:
    from do import report_working_on
except ImportError:
    report_working_on = lambda a,b: None

if len(sys.argv) > 1:
    fin = file(sys.argv[1], 'r')
    fout = file(splitext(sys.argv[1])[0]+'.out', 'w+')
else:
    fin = sys.stdin
    fout = sys.stdout

def dorun():
    cases = int(fin.next())
    for case in xrange(cases):
        report_working_on(case, cases)
        print>>fout, 'Case #%d: %s' % ( 1+case, solve(fin) )
    else:
        report_working_on(0,0)

#####################################################

def solve(fin):
    H, N, M = map(int, fin.next().split())

    F, C = {}, {}
    for i in xrange(N):
        for j,x in enumerate(map(int, fin.next().split())):
            C[i,j] = x

    for i in xrange(N):
        for j,x in enumerate(map(int, fin.next().split())):
            F[i,j] = x

    # конечная цель
    target = (N-1, M-1)
    # скорость снижения уровня воды
    vh = 10
    inf = 99999999999999

    # для каждой ячейки определяем минимальное время, 
    # за которое в нее можно попасть
    T = {}
    W = {}
    toProceed = [ (0,0) ]
    T[0,0] = 0.0

    #print 

    while len(toProceed):
        i,j = toProceed[0]
        time = T[i,j]
        del toProceed[0]

        for di,dj in [(-1,0),(1,0),(0,1),(0,-1)]:
            ni,nj = i+di, j+dj            
            if 0 <= ni < N and 0 <= nj < M:
                #print 'trying', ni, nj, 'from', i, j, time

                # можем ли мы перешагнуть в соседнюю ячейку вообще
                if C[ni,nj] - F[i,j] < 50: # пол в нашей ячейке слишком высок
                    #print 'c1', C[ni,nj], F[i,j]
                    continue
                elif C[ni,nj] - F[ni,nj] < 50: # пол в соседней ячейке слишком высок
                    #print 'c2'
                    continue
                elif C[i,j] - F[ni,nj] < 50: # наооброт
                    #print 'c3'
                    continue

                waitFor = max(time, (H - (C[ni,nj] - 50)) / vh)

                if H - vh * waitFor - F[i,j] >= 20:
                    delta = 1
                else:
                    delta = 10

                newTime = waitFor + delta if waitFor else 0

                # если полученное время - лучшее
                if T.get((ni,nj), inf) > newTime:
                    T[ni,nj] = newTime
                    toProceed += [(ni, nj)]
                    #print ni, nj , 'found best time ->', newTime

    time = T[target]
    return '%.1f' % time
      
#####################################################

if __name__=='__main__': dorun()
