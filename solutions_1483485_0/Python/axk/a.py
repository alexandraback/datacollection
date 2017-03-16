#!/usr/bin/env python

encoded = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv'
decoded = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up'

ddec = {'y': 'a', 'e': 'o', 'q': 'z'}

for i in xrange(len(encoded)):
    if encoded[i] not in ddec:
        ddec[encoded[i]] = decoded[i]

symbols = set(' abcdefghijklmnopqrstuvwxyz')
ddec[symbols.difference(set(ddec.keys())).pop()] = symbols.difference(set(ddec.values())).pop()

T = input()
for i in xrange(T):
    senc = raw_input()
    sdec = ''.join(ddec[c] for c in senc)
    print 'Case #%d: %s' % (i + 1, sdec)
