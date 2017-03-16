#!/usr/bin/python

import sys

def isConsonant(a):
    return a != 'a' and a != 'e' and a != 'i' and a !='o' and a !='u'

def count(name, n):
    total = 0
    cons = 0
    lastpos = -1
    length = len(name)
    for i in range(0,length):
        if isConsonant(name[i]):
            cons += 1
            if cons == n:
                cons -= 1
                before = i - cons
                after = length - i - 1
                if lastpos != -1:
                    before = i - cons - lastpos
                total += after + before + after * before + 1
                lastpos = i - cons + 1
        else:
            cons = 0
    return total

cases = int(sys.stdin.readline())
for case in range(1,cases+1):
    name,n = sys.stdin.readline().rstrip().split(' ')
    n = int(n)
    W = count(name, n)
    print "Case #"+str(case)+": "+str(W)
