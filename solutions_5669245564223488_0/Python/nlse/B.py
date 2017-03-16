#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')

num = int(f.readline())

for z in range(num):
    n = int(f.readline())
    trains = f.readline().split()
    trains = [re.sub(r'([a-z])\1+', r'\1', x) for x in trains]
    #print n, trains
    t1 = []
    t2 = []
    mid = []
    imp = False
    for x in trains:
        if x[0] == x[-1]:
            t1.append(x[0])
        else:
            t2.append(x[0]+x[-1])
        if len(x) > 2:
            for i in range(1,len(x)-1):
                if x[i] in mid:
                    imp = True
                mid.append(x[i])
    for m in mid:
        for t in t1:
            if m == t:
                imp = True
        for t in t2:
            if m in t:
                imp = True
    #check count
    bi = []
    en = []
    for t in t2:
        if t[0] in bi:
            imp = True
        bi.append(t[0])
        if t[1] in en:
            imp = True
        en.append(t[1])
    single = {}
    for t in t1:
        if single.has_key(t):
            single[t] += 1
        else:
            single[t] = 1
    fact = []
    for s in single:
        fact.append(single[s])
    #print t1, single, t2, mid, imp, fact
    #find block
    block = []
    while len(t2) > 0:
        b = [t2.pop()]
        bl = 0
        while bl < len(b):
            bl = len(b)
            if single.has_key(b[0][0]):
                del single[b[0][0]]
            if single.has_key(b[-1][1]):
                del single[b[-1][1]]
            for t in t2:
                if t[0] == b[-1][1]:
                    ind = t2.index(t)
                    del t2[ind]
                    b.append(t)
                elif t[1] == b[0][0]:
                    ind = t2.index(t)
                    del t2[ind]
                    b[0:0] = [t]
        block.append(b)
    #print block
    #check valid block
    for b in block:
        if b[0][0] == b[-1][1]:
            imp = True
    if imp:
        print 'Case #{}: 0'.format(z+1)
    else:
        #place single
        fact.append(len(block) + len(single))
        #print t1, single, t2, mid, imp, fact
        c = 1
        for x in fact:
            c = c*math.factorial(x) % 1000000007
        print 'Case #{}: {}'.format(z+1, c)
