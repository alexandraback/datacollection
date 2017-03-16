#! /usr/bin/python

__author__ = 'sbuono'

import sys


def probtoget(w, k):
    d = {}
    lk = len(k)
    for l in k:
        n = 0
        if l in d:
            continue
        for i in range(lk):
            if k[i] == l:
                n += 1
        d[l] = float(n) / float(lk)

    # print "dict:", d
    res = 1.0
    for l in w:
        res *= d[l]

    return res

with open(sys.argv[1], 'r') as f:
    nbtests = int(f.readline())
    lines = f.readlines()

for testnb, i in zip(range(1, nbtests+1), range(0, len(lines), 3)):

    K, L, S = (int(x) for x in lines[i].strip().split())
    keyboard = lines[i + 1].strip()
    word = lines[i + 2].strip()

    res = 0.0
    cont = True
    for l in word:
        if l not in keyboard:
            break
    else:
        if S < len(word):
            break
        m = 0
        for j in range(1, len(word)):
            for k in range(j):
                if word[k] != word[-j]:
                    break
            else:
                m = j

        # print"m:", m

        cont = True
        prob = 0.0
        nb = 1.0
        lw = len(word)
        pw = word[m - len(word):]
        lpw = lw - m
        S -= lw
        prob = probtoget(word, keyboard)
        probpw = probtoget(pw, keyboard)
        # print "p1:", prob, ", p2:", probpw, ", lpw:", lpw, ", S:", S
        while S >= lpw:
            # print "S:", S
            nb += 1.0
            S -= lpw
            prob += probpw

        # print "nb:", nb, ", probf:", prob
        res = nb - prob


    print "Case #%d: %f" % (testnb, res)