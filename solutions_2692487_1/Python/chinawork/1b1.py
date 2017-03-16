#!/usr/bin/env python

import sys, re, math

f = open(sys.argv[1])
lines = f.readlines()
f.close()

num = int(lines[0])
for case in xrange(1, num + 1):
    initV, n = tuple([int(i) for i in lines[2 * case - 1].split()])    
    values = sorted([int(i) for i in lines[2 * case].split()])
    
    n = -1
    for i in xrange(len(values)):
        v = values[i]
        if initV > v:
            initV += v
        else:
            n = i
            break
    
    if n == -1:
        result = 0
    else:
        result = 0
        
        values2 = values[n:]
        values = values[n:]
        oldi = initV
        while True:
            if len(values) == 0:
                break
            elif initV > values[0]:
                initV += values[0]
                values.pop(0)
            elif initV * 2 - 1 <= values[0]:
                result += len(values)
                break
            else:
                result += 1
                initV += initV - 1
        
        initV = oldi
        result2 = 0
        values = values2
        while True:
            if len(values) == 0:
                break
            elif initV > values[0]:
                initV += values[0]
                values.pop(0)
            elif initV - 1 == 0:
                result2 += len(values)
                break
            else:
                result2 += 1
                initV += initV - 1
        
        if result > result2:
            result = result2
    print 'Case #%d: %d' % (case, result)
