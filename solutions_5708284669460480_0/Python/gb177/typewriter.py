#!/usr/bin/python

import sys
def N(): return tuple(map(int, raw_input().split()))

from collections import defaultdict
# brute force

def countsubs(word, t):
    r = 0
    lt = len(t)
    for i in range(len(word) - lt + 1):
        if word[i:i+lt] == t:
            r += 1
    return r

assert countsubs("ababa", "aba") == 2
assert countsubs("ababa", "ccc") == 0

T = N()[0]
for t in range(1, T + 1):
    K, L, S = N()
    keyboard = raw_input()
    target = raw_input()
    #print K, L, S, keyboard, target
   
    count = defaultdict(int)
    def type(w, s):
        if s == 0:
            count[w] += 1
        else:
            for key in keyboard:
                type(w + key, s-1)

    type("", S)
    D = []
    for w, f in count.items():
        D.append((w, countsubs(w, target), f))

    needbananas = max(d[1] for d in D)
    total = sum(d[2] for d in D)
    exp = 0
    for w, c, f in D:
        exp += (needbananas - c) * f/float(total)

    print "Case #%d: %.11f" % (t, exp)

