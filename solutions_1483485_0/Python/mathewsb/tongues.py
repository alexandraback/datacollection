#!/usr/bin/env python

import fileinput, collections, sys, operator, itertools

def autodict():
    return collections.defaultdict(autodict)

def input():
    it = iter(itertools.imap(str.rstrip, fileinput.input()))
    it.next()
    while True:
        yield it.next().rstrip()

def mapone(ch):
    examplein = ('ejp mysljylc kd kxveddknmc re jsicpdrysi' +
                 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd' +
                 'de kr kd eoya kw aej tysr re ujdr lkgc jv' +
                 'qz')
    exampleout = ('our language is impossible to understand' +
                  'there are twenty six factorial possibilities' +
                  'so it is okay if you want to just give up' +
                  'zq')
    for i, inch in enumerate(examplein):
        if ch == inch:
            return exampleout[i]
    raise Exception('Fail on ' + ch)

def domap(str):
    return ''.join(
        [mapone(ch) for ch in str])


def main():
    for casenum, str in enumerate(input()):
        res = domap(str)
        print "Case #%d: %s" % (casenum+1, res)

main()
