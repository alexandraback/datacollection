#!/usr/bin/env python
#encoding=utf-8

'''
author:     Eric Zhang(snow31450588@gmail.com)
date:       2013-04-13
purpose:    Google Code Jam Qualification Round
history:
    2013-04-13  Initial version
'''

import sys
import string


def cell(ls, M, N, i, j, h):
    rsRow = True
    rsCol = True
    for row in range(M):
        if ls[row][j]>h:
            rsRow = False
            break
    
    for col in range(N):
        if ls[i][col]>h:
            rsCol = False
            break
    
    return rsRow or rsCol
    
def calc(ls):
    for i,l in enumerate(ls):
        for j,h in enumerate(l):
            if not cell(ls, len(ls), len(l), i, j, h):
                return 'NO'
    return 'YES'

def wf(fileName,results):
    f = open(fileName,'w')
    for i,r in enumerate(results):
        f.write('Case #%d: %s\n'%(i+1,r))
    f.close()

def rf(fileName):
    f = open(fileName,'r')
    inputs = []
    n = int(f.readline())
    for i in range(n):
        n,m = f.readline().strip().split()
        ls = []
        for _ in range(int(n)):
            l = f.readline().strip().split()
            ls.append([int(m) for m in l])
        inputs.append(ls)
    return inputs

def main(fin, fout):
    results = []
    
    for g in rf(fin):
        e = calc(g)
        results.append(e)
    
    wf(fout,results)


if __name__=='__main__':
    fin = sys.argv[1]
    fout = sys.argv[1][:-2]+'out'
    main(fin, fout)
    