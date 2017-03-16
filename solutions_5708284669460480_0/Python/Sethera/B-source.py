#!/usr/bin/env python
import sys

cases = []
with open(sys.argv[1]) as f:
    casecount = int(f.readline())
    for _ in xrange(0, casecount):
        k, l, s = map(int, f.readline().split(" "))
        klet = f.readline().strip()
        llet = f.readline().strip()

        cases.append((k, l, s, klet, llet))

caseno = 1
for k, l, s, klet, llet in cases:

    overlap = 0
    for x in xrange(1, l):
        if llet[x:] == llet[:l - x]:
            overlap = l - x
            break

    if overlap:
        bananas_brought = s / overlap
        if s % overlap >= l - overlap:
            bananas_brought += 1
    else:
        bananas_brought = s / l

    for letter in llet:
        if letter not in klet:
            bananas_brought = 0
            break

    bananas_left = bananas_brought

    if bananas_left:
        kcounts = {}
        for letter in klet:
            if letter in kcounts:
                kcounts[letter] += 1.0
            else:
                kcounts[letter] = 1.0

        prob = 1.0
        for letter in llet:
            prob *= kcounts[letter] / k

        bananas_left = (1.0 - prob) * bananas_left

    print "Case #%s: %s" % (caseno, bananas_left)
    caseno += 1
