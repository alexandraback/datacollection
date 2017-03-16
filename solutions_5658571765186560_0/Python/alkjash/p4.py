#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p4.out", "w")

T = int(fin.readline())

for i in xrange(T):
    X, R, C = map(int, fin.readline().split())
    R, C = sorted((R, C))    # R <= C
    ans = "GABRIEL"
    if 2 * R < X:            # L won't fit
        ans = "RICHARD"
    elif C < X:              # I won't fit
        ans = "RICHARD"
    elif ((R * C) % X) != 0: # Not divisible
        ans = "RICHARD"
    elif (X, R) in [(4, 2), (6, 3)]: # T tetrominoes
        ans = "RICHARD"
    elif X >= 7:             # Holes
        ans = "RICHARD"

    if ans not in ["GABRIEL", "RICHARD"]:
        print "Error!"
    fout.write("Case #" + str(i+1) + ": " + ans + "\n")
