#!/usr/bin/env pypy
import sys, os
import itertools

outfile = sys.argv[1]
t = int(sys.stdin.readline())

def incr(chiffre, cible):
    count = 0
    while chiffre <= cible:
        chiffre = chiffre * 2 - 1
        count += 1
    return chiffre, count

def rec(liste, ind, depart):
    count = 0
    while ind < len(liste):
        mote = liste[ind]
        if depart > mote:
            depart += mote
            ind += 1
        else:
            if depart == 1:
                count += 1 + rec(liste, ind + 1, depart)
            else:
                chiffre, c = incr(depart, mote)
                by_add = c + rec(liste, ind + 1, chiffre + mote)
                by_del = 1 + rec(liste, ind + 1, depart)
                count += min(by_add, by_del)
            break
    return count
    

with open(outfile, "w") as f:
    for case in xrange(t):
        size, number = map(int, sys.stdin.readline().rstrip('\n').split())
        motes = map(int, sys.stdin.readline().rstrip('\n').split())
        motes.sort()
        result = rec(motes, 0, size)
        f.write("Case #%d: %d\n" % (case + 1, result))
