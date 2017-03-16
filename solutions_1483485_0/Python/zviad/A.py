#!/usr/bin/env python

import sys

mapping = ["y", "h", "e", "s", "o",
           "c", "v", "x", "d", "u",
           "i", "g", "l", "b", "k",
           "r", "z", "t", "n", "w",
           "j", "p", "f", "m", "a", "q"]

for i, line in enumerate(sys.stdin.readlines()[1:]):
    line = line.strip()
    newline = ""
    for c in line:
        if c == " ":
            newline += " "
        else:
            newline += mapping[ord(c) - ord('a')]
    
    print "Case #%d: %s" % (i+1, newline)
    
        

