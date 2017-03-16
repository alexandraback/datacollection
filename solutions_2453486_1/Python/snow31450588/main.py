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


def win(chars):
    if '.' in chars:
        return
    
    X = chars.count('X')
    O = chars.count('O')
    T = chars.count('T')
    if X+T==4:
        return 'X'
    if O+T==4:
        return 'O'
    
def cell(ls, i, j):
    start = ls[i][j]
    if start == '.':
        return
    
    if i==0:
        rs = win([ls[row][j] for row in range(4)])
        if rs:
            return rs
    
    if j==0:
        rs = win([ls[i][col] for col in range(4)])
        if rs:
            return rs
    
    if i==0 and j==0:
        rs = win([ls[row][row] for row in range(4)])
        if rs:
            return rs
    
    if i==0 and j==3:
        rs = win([ls[row][3-row] for row in range(4)])
        if rs:
            return rs
    

def calc(ls):
    for i in range(4):
        for j in range(4):
            success = cell(ls, i, j)
            if success:
                return success+' won'
    for l in ls:
        if '.' in l:
            return 'Game has not completed'
    
    return 'Draw'

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
        ls = []
        for _ in range(4):
            l = f.readline().strip()
            ls.append(l)
        inputs.append(ls)
        f.readline()
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
    