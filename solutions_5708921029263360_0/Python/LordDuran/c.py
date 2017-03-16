# from __future__ import division
from pprint import pprint
import time
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
parse_linef = lambda: [float(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")
INF = 10**9

def do_case(ncase):
    J, P, S, K = parse_line()

    timesJP = {}
    timesJS = {}
    timesPS = {}
    combos = []
    for j in xrange(J-1, -1, -1):
        for p in xrange(P-1, -1, -1):
            for s in xrange(S-1, -1, -1):
                if timesJP.get((j, p), 0) < K and \
                   timesJS.get((j, s), 0) < K and \
                   timesPS.get((p, s), 0) < K:
                   timesJP[(j,p)] = timesJP.get((j,p), 0) + 1
                   timesJS[(j,s)] = timesJS.get((j,s), 0) + 1
                   timesPS[(p,s)] = timesJP.get((p,s), 0) + 1
                   combos.append((j, p, s))

    print >>outputfile, out_s % (ncase, str(len(combos)))
    for combo in combos:
        print >>outputfile, '%d %d %d' % (combo[0]+1, combo[1]+1, combo[2]+1)

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    
