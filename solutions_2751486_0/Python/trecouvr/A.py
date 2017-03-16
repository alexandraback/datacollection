#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division

def split_input(f=int):
    return [ f(x) for x in raw_input().split() ]

vowels = ('a','e','i','o','u')

runs = input()
for run in xrange(1,runs+1):
    s,n = raw_input().split()
    n = int(n)
    assert len(s) >= n
    
    r = 0
    li = 0
    for i in xrange(0, len(s)-n+1):
        cv = 0
        ss = s[i:i+n]
        for x in ss:
            if x not in vowels:
                cv += 1
            else:
                break
        if cv == n:
            if i == 0:
                #print "a"
                r += len(s) - n + 1
                li = i+1
            elif i == len(s) - n:
                #print "b"
                r += (i-li) + 1
            else:
                a = len(s) - (i+n-1)
                #print "c"
                r += (i-li+1) * a
                li = i+1
            #print i,r
            
    
    print "Case #%d: %d" % (run, r)
