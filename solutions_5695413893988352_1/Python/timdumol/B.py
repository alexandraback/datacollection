#-*- encoding: utf-8 -*-

from __future__ import print_function
from __future__ import absolute_import
from __future__ import unicode_literals
from __future__ import division


def recurse(i, a, b):
    if i == n:
        return (a, b)
    if a_str[i] == '?' and b_str[i] == '?':
        if a < b:
            a = 10*a + 9
            b = 10*b + 0
            return recurse(i+1, a, b)
        elif a == b:
            a = 10*a
            b = 10*b

            # Try for equal, lt, gt
            x, y = recurse(i+1, a, b)
            #print('%s v1: %s %s' % (i, x, y))
            x2, y2 = recurse(i+1, a, b+1)
            #print('%s v2: %s %s' % (i, x2, y2))
            if abs(x - y) > abs(x2 - y2):
                x, y = x2, y2
            x3, y3 = recurse(i+1, a+1, b)
            #print('%s v3: %s %s' % (i, x3, y3))
            if abs(x - y) > abs(x3 - y3):
                x, y = x3, y3
            return x, y
        else:
            a = 10*a + 0
            b = 10*b + 9
            return recurse(i+1, a, b)
    elif a_str[i] == '?':
        if a < b:
            a = 10*a + 9
            b = 10*b + int(b_str[i])
            return recurse(i+1, a, b)
        elif a == b:
            a = 10*a + int(b_str[i])
            b = 10*b + int(b_str[i])

            # Try for lt, equal, gt
            x, y = recurse(i+1, a, b)

            if b_str[i] != '0':
                x2, y2 = recurse(i+1, a-1, b)
                if abs(x - y) >= abs(x2 - y2):
                    x, y = x2, y2
            if b_str[i] != '9':
                x3, y3 = recurse(i+1, a+1, b)
                if abs(x - y) > abs(x3 - y3):
                    x, y = x3, y3
            return x, y
        else:
            a = 10*a + 0
            b = 10*b + int(b_str[i])
            return recurse(i+1, a, b)
    elif b_str[i] == '?':
        if a < b:
            a = 10*a + int(a_str[i])
            b = 10*b + 0
            return recurse(i+1, a, b)
        elif a == b:
            a = 10*a + int(a_str[i])
            b = 10*b + int(a_str[i])

            # Try for gt, equal, lt
            x, y = recurse(i+1, a, b)

            #print('%s v1: %s %s' % (i, x, y))
            if a_str[i] != '0':
                x2, y2 = recurse(i+1, a, b-1)
                #print('%s v2: %s %s' % (i, x2, y2))
                if abs(x - y) >= abs(x2 - y2):
                    x, y = x2, y2
            if a_str[i] != '9':
                x3, y3 = recurse(i+1, a, b+1)
                #print('%s v3: %s %s' % (i, x3, y3))
                if abs(x - y) > abs(x3 - y3):
                    x, y = x3, y3
            return x, y
        else:
            a = 10*a + int(a_str[i])
            b = 10*b + 9
            return recurse(i+1, a, b)
    else:
        a = 10*a + int(a_str[i])
        b = 10*b + int(b_str[i])
        return recurse(i+1, a, b)


n_cases = int(input())
for ctr in range(n_cases):
    a_str, b_str = input().split()

    n = len(a_str)

    a, b = recurse(0, 0, 0)

    print('Case #%d: %0*d %0*d' % (ctr+1, n, a, n, b))
