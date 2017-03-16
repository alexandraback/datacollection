#! /usr/bin/python

import os, sys

T = int(raw_input())

lst = [(1, 1), (6, 3), (15, 5)]

lst = []
d = 0
for i in range(10**5):
    d += i
    if i % 2 <> 0:
        lst.append((d,i))

# For each test case
for t in range(1, T+1):
    [N, mX, mY] = [int(x) for x in raw_input().split(' ')]
    remaining = 0
    result = None
    if N == 0:
        result = 0
    elif N == 1:
        if mX == 0 and mY == 0:
            result = 1
        else:
            result = 0
    elif N >= 1 and  mX == 0 and mY == 0:
        result = 1
    elif mX == 0:       
        for (l,m) in lst:
            if mY == m and N >= l:
                result = 1
            elif N < l:
                result = 0
    else:
        for (l, m) in lst:
            if N >= l:
                total_b = l
                remaining = N - total_b
                max_x = m - 1
                max_y = m - 1
        if abs(mX) <= abs(max_x) and abs(mY) <= abs(max_y):
            result = 1
        else:
            result = 0
            to_remove = 0
            needed = 0

            n = 0
            d = 1
            #print 'range for : %s' % (abs(mX) - abs(max_x))
            rng = mX / 2 if mX % 2 == 0 else (mX / 2) + 1
            for i in range(0, rng):
                n += max_y + d
                d += 1

            n+= mY / 2 if mY % 2 == 0 else (mY / 2) + 1
            #print 'n : %s' % (n)

            #print 'remaining %s' % remaining
            while True:
                #print 'needed %s' % needed
                if remaining >= n + needed:
                    clause =  0.5**(n+needed)
                    result += clause
                    #print 'adding for n = %s, %s' % (n, clause)
                    needed += 1
                else:
                    break

    #print 'total %s, remaining %s' % (N, remaining)
    print 'Case #%s: %.10f' % (t, result)
