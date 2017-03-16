#!/usr/bin/env python

import sys

def maxBananas(kb, tgt, s):
    if s < len(tgt):
        return 0
    for letter in tgt: 
        if letter not in kb:
            return 0
    nonOverlapSize = overlapStart(tgt)
    return (s - len(tgt))/nonOverlapSize + 1

def overlapStart(tgt):
    for j in range(1, len(tgt)):
        if tgt[j:] == tgt[:-j]:
            return j
    return len(tgt)

def kbProb(letter, kb):
    count = 0
    for key in kb:
        if key == letter:
            count += 1
    return count / float(len(kb))

def expected(tgt, kb, s):
     if s < len(tgt):
         return 0.0
     baseProb = 1.0
     for letter in tgt:
         baseProb = baseProb * kbProb(letter, kb)
     return baseProb * (1 + s - len(tgt))


t = int(sys.stdin.readline())
for i in range(1,t+1):
    k, l, s = map(int, sys.stdin.readline().split(' '))
    keyboard = sys.stdin.readline()[:k]
    target = sys.stdin.readline()[:l]
    m = maxBananas(keyboard, target, s)
    if m == 0:
        print "Case #" + str(i) + ": 0.0"
        continue
    print "Case #" +  str(i) + ": " + str(m - expected(target, keyboard, s))
