#!/usr/bin/env python

import sys

import string

infile=open(sys.argv[1])

tr0=[ 
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"yeq",
"z"
]
tr1=[
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"aoz",
"q"
]

transtr=string.maketrans("".join(tr0), "".join(tr1))

#print transtr

for n,line in enumerate(infile):
    if n==0:
        N=int(line)
        continue
    print "Case #%d: %s" % (n,line.strip().translate(transtr))

