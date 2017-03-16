#!/usr/bin/env python
# -*- coding: utf-8 -*-
import fileinput
from math import log,ceil

fin=fileinput.input()
T = int(fin.readline())

def readData():
        A,N = [int(n) for n in fin.readline().split()]
        motes = [int(n) for n in fin.readline().split()]
        motes.sort()
        assert (len(motes) == N)
        return A,motes

def solve(A,motes):
        N = len(motes)
        if (A == 1):
                return N
        curcost = 0
        costs = [0]
        cur = A
        for m in motes:
                if m < cur:
                        cur += m
                        costs.append(curcost)
                        continue
                else:
                        cost = ceil( log(m,2) - log(cur-1, 2) )
                        curcost += cost
                        costs.append(curcost)
                        cur += (2**cost-1)*(cur-1) + m
        for i in range(N+1):
                costs[i] += (N-i)
        return min(costs)


for i in range(T):
        A,motes = readData()
        print "Case #%d: %d" % (i+1,solve(A,motes))
