defs = [
    ['y qee', 'a zoo'],
    ['ejp mysljylc kd kxveddknmc re jsicpdrysi', 'our language is impossible to understand'],
    ['rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities'],
    ['de kr kd eoya kw aej tysr re ujdr lkgc jv', 'so it is okay if you want to just give up'],
    ['z', 'q'],
]
h = {}
for first, second in defs:
    for i in xrange(len(first)):
        if first[i] in h and h[first[i]] != second[i]:
            print "conflict"
        h[first[i]] = second[i]

def trans(text):
    s = ""
    for c in text:
        s += h[c]
    return s

import sys
lines = sys.stdin.read().split("\n")[1:-1]
count = 0
for line in lines:
    count += 1
    print "Case #%i: %s" % (count, trans(line))
