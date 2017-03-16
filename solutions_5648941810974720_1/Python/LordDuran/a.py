# from __future__ import division
from pprint import pprint

import time
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

DIGITS = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
LETTERS = sorted(list(set(''.join(DIGITS))))
from numpy import linalg, matrix
from math import ceil, floor

Mat = matrix([
[1, 1, 0, 2, 0, 1, 0, 2, 1, 1], #Es
[0, 0, 0, 0, 1, 1, 0, 0, 0, 0], #Fs
[0, 0, 0, 0, 0, 0, 0, 0, 1, 0], #Gs
[0, 0, 0, 1, 0, 0, 0, 0, 1, 0], #Hs
[0, 0, 0, 0, 0, 1, 1, 0, 1, 1], #Is
[0, 1, 0, 0, 0, 0, 0, 1, 0, 2], #Ns
[1, 1, 1, 0, 1, 0, 0, 0, 0, 0], #Os
[1, 0, 0, 1, 1, 0, 0, 0, 0, 0], #Rs
[0, 0, 0, 0, 0, 0, 1, 1, 0, 0], #Ss
[0, 0, 1, 1, 0, 0, 0, 0, 1, 0], #Ts
[0, 0, 0, 0, 1, 0, 0, 0, 0, 0], #Us
[0, 0, 0, 0, 0, 1, 0, 1, 0, 0], #Vs
[0, 0, 1, 0, 0, 0, 0, 0, 0, 0], #Ws
[0, 0, 0, 0, 0, 0, 1, 0, 0, 0], #X
[1, 0, 0, 0, 0, 0, 0, 0, 0, 0] #Zs
])

lines = []
for letter in LETTERS:
    lines.append([d.count(letter) for d in DIGITS])
Mat = matrix(lines)

def do_case(ncase):
    letters = list(rl())
    counts = matrix([letters.count(c) for c in LETTERS]).transpose()
    sol = linalg.lstsq(Mat, counts)
    sol = [int(round(x)) for x in sol[0]]
    parts = []
    for i in xrange(10):
        parts.append(str(i) * sol[i])

    print >>outputfile, out_s % (ncase, str(''.join(parts)))

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    