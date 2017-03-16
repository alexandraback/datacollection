#!/usr/bin/env python

import sys

f = open(sys.argv[1])
lines = f.readlines()
f.close()

num = int(lines[0].strip())

trans = {'T' : 100, 'X' : 1, 'O' : -1, '.' : 0}
result = {4 : 'X', -4 : 'O', 103 : 'X', 97 : 'O'}

for case in xrange(1, (num + 1)):
    lineStart = (case - 1) * 5 + 1
    lineEnd = lineStart + 4
    
    data = {}
    row = {}
    column = {}
    cross = {}
    bHole = False
    
    for i in xrange(0, 4):
        for j in xrange(0, 4):
            item = trans[lines[lineStart + i][j]]
            if item == 0:
                bHole = True
            
            row.setdefault(i, 0)
            row[i] += item
            
            column.setdefault(j, 0)
            column[j] += item
            
            cross.setdefault(0, 0)
            if j == i:
                cross[0] += item
            
            cross.setdefault(1,0)
            if i + j == 3:
                cross[1] += item
                
    #check results
    win = ''
    for i in xrange(0, 4):
        if column[i] in result.keys():
            win = result[column[i]]
            break
        if row[i] in result.keys():
            win = result[row[i]]
            break
        if i < 2 and cross[i] in result.keys():
            win = result[cross[i]]
            break
    
    print 'Case #%d:' % case,
    if win != '':
        print '%c won' % win
    elif bHole == True:
        print 'Game has not completed'
    else:
        print 'Draw'

    
    

