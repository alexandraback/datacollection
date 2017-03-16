#!/usr/bin/env python
from itertools import *
from bisect import *
import fileinput

N=53
l = [0,1,2,3]

def p(x):
    l.append(int(x))


def comb(k, middle):
    for i in xrange(N/2):
        indices = xrange(i)
        for ones in combinations(indices, k):
            txt = ["1"]
            for j in xrange(i):
                if j in ones:
                    txt.append("1")
                else:
                    txt.append("0")
            p("".join(txt + [middle] + txt[::-1]))


for i in xrange(4):
    comb(i, "")
    comb(i, "0")
    comb(i, "1")

comb(0, "2")
comb(1, "2")

for i in xrange(N):
    p("2" + ("0"*i) + "2")
for i in xrange(N/2):
    p("2" + ("0"*i) + "1" + ("0"*i) + "2")


l = list(set(l))
l.sort()

l2 = []
x10100 = 10**100
for x in l:
    x2 = x*x
    if x2 <= x10100:
        l2.append(x*x)

lines = list(fileinput.input())

T=int(lines[0].strip())

for i, line in zip(xrange(T), lines[1:]):
    line.strip()
    A, B = line.split(" ")
    A, B = int(A), int(B)
    res = bisect_right(l2, B) - bisect_left(l2, A)
    print "Case #%d: %d" % ((i+1), res)

