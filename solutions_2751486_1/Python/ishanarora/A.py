#!/usr/bin/env python

T = int(raw_input())
for t in range(T):
    print "Case #%d:" % (t+1,),
    name, n = raw_input().split(' ')
    n = int(n)
    L = len(name)
    p = 0 # number of consecutive consonants at the end
    m = 0 # 1 + beginning of the last n-consecutive
    a = 0 # answer
    for i in range(len(name)):
        if name[i] in 'aeiou':
            p = 0
        else:
            p += 1
            if p >= n:
                m = i + 2 - n
        a += m
    print a
