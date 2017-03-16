# from __future__ import division
from pprint import pprint
import time
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

def do_case(ncase):
    C, J = rl().split()
    clen = len(C)
    mindiff = 1000
    minopt = None
    for pc in xrange(10**clen):
        pcs = str(pc).rjust(clen, '0')
        cgood = True
        for x,y in zip(pcs, C):
            if x != y and y != '?':
                cgood = False
                break
        if cgood == False:
            continue
        for pj in xrange(10**clen):
            pjs = str(pj).rjust(clen, '0')
            jgood = True
            for x,y in zip(pjs, J):
                if x != y and y != '?':
                    jgood = False
                    break
            if jgood == False:
                continue
            diff = abs(pj-pc)
            if diff < mindiff:
                mindiff = diff
                minopt = (pc, pj)
            elif diff == mindiff:
                if pc < minopt[0]:
                    minopt = (pc, pj)
                elif pc == minopt[0]:
                    if pj < minopt[1]:
                        minopt = (pc, pj)

    print >>outputfile, out_s % (ncase, str(str(minopt[0]).rjust(clen, '0') + ' ' + str(minopt[1]).rjust(clen, '0')))

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    