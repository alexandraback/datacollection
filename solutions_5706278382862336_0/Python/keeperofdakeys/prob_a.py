#!/usr/bin/env python
from fractions import gcd
from math import log

def find_two_factor(b):
    num = 1
    exp = 0
    result = False
    while num <= b:
        if num == b:
            result = True
            break
        num *= 2
        exp += 1

    return (num, exp, result)


count = int(raw_input())
for x in xrange(1,count+1):
    values = raw_input().split("/")
    a = int(values[0])
    b = int(values[1])

    fac = gcd(a, b)
    if fac > 1:
        a = a / fac
        b = b / fac

    num = 1
    test = a
    test_count = 0
    exp = 0
    result = False
    while num <= b:
        if num == b:
            result = True
            break
        num *= 2
        exp += 1
        if test > 1:
            test = test // 2
            test_count += 1

    

    if result:

        print ("Case #" + str(x) + ": " + str(exp - test_count))
    else:
        print ("Case #" + str(x) + ": impossible")
