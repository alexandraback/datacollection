#!/usr/bin/env python
import sys

cases = []
with open(sys.argv[1]) as f:
    casecount = int(f.readline())
    for _ in xrange(0, casecount):
        r, c, w = map(int, f.readline().split(" "))

        cases.append((r, c, w))

caseno = 1
for r, c, w in cases:

    to_find = (c / w) * r

    to_sink = to_find + (w - 1)

    if c % w != 0:
        to_sink += 1

    print "Case #%s: %s" % (caseno, to_sink)
    caseno += 1
