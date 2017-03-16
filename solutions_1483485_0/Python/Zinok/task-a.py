#!/usr/bin/env python2.6

import sys
import string

# initial mapping
lmap = {
    'y': 'a',
    'e': 'o',
    'q': 'z'
}

# calculate mapping from given example
text_en = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
text_de = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

for i in xrange(len(text_en)):
    c_en = text_en[i]
    c_de = text_de[i]
    lmap[c_en] = c_de
    
# make translation table
translation = string.maketrans(''.join(lmap.keys()), ''.join(lmap.values()))

# get number of cases
num = int(sys.stdin.readline())

# read cases data
cases = [row.strip() for row in sys.stdin.readlines()]

for i in xrange(num):
    case = cases[i].translate(translation)
    print "Case #%d: %s" % (i+1, case)

