#! /usr/bin/env python
import sys, re
from fractions import Fraction
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())

numdigits = lambda n: int(math.log10(n)) + 1

""" END TEMPLATE JCHAOISAAC """

# global data

printHall = lambda h: '\n'.join(h)

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    H, W, D = getints()
    hall = []
    j = None
    for r in xrange(H):
        row = getline()
        idx = row.find('X')
        if idx != -1:
            i = r - 1
            j = idx - 1

    H -= 2
    W -= 2
    dh2 = 2 * i + 1
    dh1 = 2 * H - dh2
    dw2 = 2 * j + 1
    dw1 = 2 * W - dw2

    adj_H = 2 * H
    adj_W = 2 * W
    adj_i = 2 * i + 1
    adj_j = 2 * j + 1

    adj_dh1 = 2 * dh1
    adj_dh2 = 2 * dh2
    adj_dw1 = 2 * dw1
    adj_dw2 = 2 * dw2

    adj_D = 2 * D

    taboo = {}

    meh = adj_i
    dmeh = adj_dh1
    me_h = [adj_i]
    while abs(meh - adj_i) <= adj_D:
        meh += dmeh
        dmeh = adj_dh1 if dmeh == adj_dh2 else adj_dh2
        me_h.append(meh)
    meh = adj_i
    dmeh = adj_dh2
    while abs(meh - adj_i) <= adj_D:
        meh -= dmeh
        dmeh = adj_dh1 if dmeh == adj_dh2 else adj_dh2
        me_h.append(meh)

    mew = adj_j
    dmew = adj_dw1
    me_w = [adj_j]
    while abs(mew - adj_j) <= adj_D:
        mew += dmew
        dmew = adj_dw1 if dmew == adj_dw2 else adj_dw2
        me_w.append(mew)
    mew = adj_j
    dmew = adj_dw2
    while abs(mew - adj_j) <= adj_D:
        mew -= dmew
        dmew = adj_dw1 if dmew == adj_dw2 else adj_dw2
        me_w.append(mew)

    me = []
    for mew in me_w:
        for meh in me_h:
            me.append((meh, mew))
            
    def fucker(x):
        d1 = x[0] - adj_i
        d2 = x[1] - adj_j
        d = d1 * d1 + d2 * d2
        return d
    me.sort(key=fucker)

    for m in me:
        (meh, mew) = m
        dh = meh - adj_i
        dw = mew - adj_j
        if dh == 0 and dw == 0:
            continue
        dist = math.sqrt(dh * dh + dw * dw)
        if dist > adj_D:
            continue
        

        f = Fraction(dh, dw) if dw != 0 else None

        fail = False
        if f in taboo:
            for taboo_v in taboo[f]:
                # print '          ', (adj_i, adj_j), taboo_v, (meh, mew)
                if (((adj_i <= taboo_v[0] <= meh) or
                     (meh <= taboo_v[0] <= adj_i)) and
                    ((adj_j <= taboo_v[1] <= mew) or
                     (mew <= taboo_v[1] <= adj_j))):
                    fail = True
                    break
            if fail:
                continue

        ans += 1
        keya = Fraction(dh, dw) if dw != 0 else None
        if keya not in taboo: taboo[keya] = []
        taboo[keya].append((meh, mew))
        #print (meh, mew)


    # main
    print "Case #%d: %d" % (cases, ans) # answer output
