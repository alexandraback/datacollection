#!/usr/bin/env python

import os, sys

def binones (num, line):
    num = bin(num)[2:]
    num = (line - len(num)) * '0' + num
    l = []
    x = len(num)
    cnt = 0
    while cnt < x:
        cnt = num.find("1", cnt)
        if cnt == -1:
            break
        l.append(cnt)
        cnt += 1
    return l
        

def solve (line):
    line = line[1:]
    line.sort()
    line.reverse()
    s1 = []
    s2 = []

    num = eval('0b' + '1' * len(line))

    cnt = 1
    numset = {}
    while cnt <= num:
        l = binones(cnt, len(line))
        l = [line[x] for x in l]
        suml = sum(l)
        if numset.has_key(suml):
            return str(" ".join([str(x) for x in numset[suml]]) + "\n" + " ".join([str(x) for x in l]))
        else:
            numset[suml] = l
        cnt += 1

    return "Impossible"


fd = sys.stdin

line = fd.readline()
sets = int(line)+1

for case in range(1, sets):
    line = [int(x) for x in fd.readline().strip().split()]
    nline = solve(line)
    print "Case #%s: \n%s" % (case, nline)

fd.close()
