#!/usr/bin/python

import sys
import math

if __name__=="__main__":
    data = sys.stdin.readlines()
    for id, line in enumerate(data[1:]):
        digit = line.strip().split(' ')
        n,s,p = int(digit[0]), int(digit[1]), int(digit[2])
        digit = digit[3:]
        res = 0
        for val in digit:
            g =int(val)
            if g < p:
                continue

            if p * 3 <= g:
                res += 1
            elif max(p * 3 - 2,0) <= g  < p * 3:
                res += 1
            elif max(p * 3 - 4,0) <= g < max(p * 3 - 2,0) and s > 0:
                res += 1
                s -= 1
        print "Case #%d: %d" %(id+1, res)
