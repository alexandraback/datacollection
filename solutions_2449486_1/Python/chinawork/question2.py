#!/usr/bin/env python

import sys

f = open(sys.argv[1])
lines =  f.readlines()
f.close()

num = int(lines[0])
lineNum = 0
for case in xrange(1, num + 1):
    lineNum += 1
    a = [int(i) for i in lines[lineNum].split()]
    n, m = a[0], a[1]
    data = {}
    rowMax = [0] * n
    colMax = [0] * m
    
    for i in xrange(0, n):
        lineNum += 1
        data[i] = [int(j) for j in lines[lineNum].split()][:m]
        rowMax[i] = max(data[i])
        
        for j in xrange(0, m):
            if data[i][j] > colMax[j]:
                colMax[j] = data[i][j]
        
    bValid = True
    for i in xrange(0, n):
        for j in xrange(0, m):
            if data[i][j] < colMax[j] and data[i][j] < rowMax[i]:
                bValid = False
                break
    
    print 'Case #%d:' % case,
    if bValid:
        print 'YES'
    else:
        print 'NO'
        
    
        
        
    
    