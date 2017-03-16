#! /opt/local/bin/python

import sys, itertools

key = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

def getline(file=sys.stdin):
    return file.readline().strip()

def out(s):
    if False:
        print s

def getKey():
    f = open('key.txt')
    cases = int(getline(f))
    key = {}
    for case in xrange(cases):
        g = getline(f)
        e = getline(f)
        for l in xrange(len(g)):
            key[g[l]] = e[l]
    return key

def solve(casenum, key):
    answer = ''.join((key[l] for l in getline().strip()))
    print 'Case #%d: %s' % (casenum, answer)

#key = getKey()
#print key
cases = int(getline())
for case in xrange(cases):
    solve(case + 1, key)
