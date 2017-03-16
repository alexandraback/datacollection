#!/usr/bin/python

exampleData = [
    ('y qee',
     'a zoo'),
    ('ejp mysljylc kd kxveddknmc re jsicpdrysi',
     'our language is impossible to understand'),
    ('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
     'there are twenty six factorial possibilities'),
    ('de kr kd eoya kw aej tysr re ujdr lkgc jv',
     'so it is okay if you want to just give up')]


subst = {' ': ' '}
for enc, msg in exampleData:
    for e, m in zip(enc, msg):
        if e in subst:
            assert subst[e] == m
        else:
            subst[e] = m
abet = set(map(chr, range(ord('a'), ord('z') + 1)))
missingKey = (abet - set(subst)).pop()
missingVal = (abet - set(subst.values())).pop()
subst[missingKey] = missingVal

def solve(s):
    return ''.join(map(lambda c: subst[c], s))

T = int(raw_input())
for i in range(T):
    print "Case #%i: %s" % (i+1, solve(raw_input()))

