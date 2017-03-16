#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())

""" END TEMPLATE JCHAOISAAC """

# global data

s = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
t = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

d = {}
for (a, b) in zip(s, t):
    d[a] = b

#print sorted(list(d.itervalues()))

# second pass fill in after guess
d['q'] = 'z'
d['z'] = 'q'

# global data

[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    l = ''.join([d[x] for x in getline()])

    # main
    print "Case #%d: %s" % (cases, l) # answer output
