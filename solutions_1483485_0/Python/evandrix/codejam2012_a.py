#!/usr/bin/env python

import sys
import string
import itertools
from pprint import pprint

# construct dictionary
sz_g = """
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
"""
sz_e = """
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
"""
def isletter(x):
    return ord('a') <= ord(x) <= ord('z')
#eng->goog
translation = { 'a': 'y', 'o':'e', 'z':'q' }
for g,e in itertools.izip(sz_g.strip(),sz_e.strip()):
    if isletter(e) and isletter(g):
        if e not in translation:
            #print "Adding %s->%s to translation..." % (e,g)
            translation[e] = g
        else:
            pass
            #print "Translation %s->%s already exists!" % (e,g)

missing_e = [ letter for letter in string.ascii_lowercase if letter not in translation.keys() ]
missing_g = [ letter for letter in string.ascii_lowercase if letter not in translation.values() ]
for e,g in itertools.izip(missing_e, missing_g):
    translation[e] = g

#pprint(translation)
#print len(translation)

the_dictionary = {}
for k,v in translation.iteritems():
    the_dictionary[v] = k

with open('A-small-attempt0.in', 'r') as f:
    lines = f.readlines()
    cc = int(lines[0])
    lines = lines[1:]
    for c in xrange(cc):
        line_in_g = lines[c]
        print "Case #%d: " % (c+1),
        for c in line_in_g:
            if isletter(c):
                sys.stdout.write(the_dictionary[c])
            else:
                sys.stdout.write(c)
