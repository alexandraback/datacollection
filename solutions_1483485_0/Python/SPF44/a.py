#!/usr/bin/python

import string

def buildDictionary(eng, goog):
    d = {}
    for i in range(len(eng)):
        d[string.lower(goog[i])] = string.lower(eng[i])
        d[string.upper(goog[i])] = string.upper(eng[i])
    return d

########################################

g1 = 'ejp mysljylc kd kxveddknmc re jsicpdrysi'
e1 = 'our language is impossible to understand'
g2 = 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'
e2 = 'there are twenty six factorial possibilities'
g3 = 'de kr kd eoya kw aej tysr re ujdr lkgc jv'
e3 = 'so it is okay if you want to just give up'
goog = g1 + ' ' + g2 + ' ' + g3 + ' qz'
eng  = e1 + ' ' + e2 + ' ' + e3 + ' zq'

toEng = buildDictionary(eng, goog)

T = int(raw_input())
for i in range(T):
    s = raw_input()
    print 'Case #' + str(i + 1) + ': ' + reduce(lambda x,y: x+y, map(lambda x: toEng[x], s))

