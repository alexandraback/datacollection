# from __future__ import division
# from pprint import pprint
import time
from string import maketrans, translate

inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

import sys

INF = sys.maxint

trans_table = maketrans("-+", "+-")

def flip(S):
    return hflip(S)[::-1]

def hflip(S):
    return translate(S, trans_table)

raws = False
def flips(S, even=True):
    if S == '':
        return 0
    if (even and S[-1] == '+') or (not even and S[-1] == '-'):
        return flips(S[:-1], even)
    return flips(S[:-1], not even) + 1

def do_case(ncase):
    S = rl()
    print >>outputfile, out_s % (ncase, str(flips(S)))

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time

    