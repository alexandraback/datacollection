# from __future__ import division
from pprint import pprint
import time
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

def do_case(ncase):
    N, = parse_line()
    pairs = []
    for i in xrange(N):
        pairs.append(rl().split())

    maxnum = 0
    for i in xrange(2**N):
        fakes = [False] * N
        for k in xrange(N):
            if (i>>k)&1 == 1:
                fakes[k] = True
        starts = set()
        ends = set()
        for k in xrange(N):
            if fakes[k]:
                continue
            starts.add(pairs[k][0])
            ends.add(pairs[k][1])
        good = True
        for k in xrange(N):
            if not fakes[k]:
                continue
            if pairs[k][0] not in starts:
                good = False
                break
            if pairs[k][1] not in ends:
                good = False
                break
        if good:
            maxnum = max(fakes.count(True), maxnum)
    print >>outputfile, out_s % (ncase, str(maxnum))

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    