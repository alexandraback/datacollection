#!/usr/bin/env python
# -*- coding: utf-8 -*-
code=dict()
code['X'] = 1
code['O'] = -1
code['T'] = 0
code['.'] = 100

lines = [ [0,1,2,3],  [4,5,6,7],  [8,9,10,11], [12,13,14,15],\
          [0,4,8,12], [1,5,9,13], [2,6,10,14], [3,7,11,15],\
          [0,5,10,15],[3,6,9,12] ]

def do_code(c):
    return code[c]

def read_table():
    table = []
    for i in range(4):
        table.extend(map(do_code,raw_input()))
    raw_input()
    return table

def solve(table):
    partial = False
    for l in lines:
        extract = [table[i] for i in l]
        if (sum(extract) > 96):
            partial = True
            continue
        if (sum(extract) > 2):
            print "X won"
            return None
        if (sum(extract) < -2):
            print "O won"
            return None
    if partial:
        print "Game has not completed"
    else:
        print "Draw"


T = int(raw_input())

for t in xrange(T):
    table = read_table()
    print "Case #%d:"%(t+1),
    solve(table)
