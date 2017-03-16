#!/usr/bin/env python

import sys
ls = sys.stdin.readlines()[1:]

i = 1
for s in ls:
    out = ""
    for c in s.strip():
        if len(out) == 0 or c >= out[0]:
            out = c + out
        else:
            out += c
    print "Case #%d: %s" % (i, out)
    i += 1

        
