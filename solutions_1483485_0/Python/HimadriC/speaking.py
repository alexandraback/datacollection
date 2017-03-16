#!/usr/bin/env python

import sys


lines = ["ejp mysljylc kd kxveddknmc re jsicpdrysi",
"our language is impossible to understand",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"there are twenty six factorial possibilities",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"so it is okay if you want to just give up"]

memo={}
for j in xrange(3):
    for i in xrange(len(lines[2*j])):
        memo[lines[2*j][i]] = lines[2*j+1][i]

memo['q'] = 'z'

memo['z'] = 'q'

T = int(sys.stdin.readline())

for zz in xrange(T):
    inp = sys.stdin.readline().rstrip()
    ret = ""
    for i in xrange(len(inp)):
        ret += memo[inp[i]]

    print "Case #%d: %s" % (zz+1,ret)

