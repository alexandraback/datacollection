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

import itertools
import networkx as nx
def ways(g, src, tgt):
    if src == tgt:
        return 1
    return sum(ways(g, e, tgt) for e in g.neighbors(src))

def do_case(ncase):
    B, M = parse_line()
    if M > 2**(B-2):
        print >>outputfile, out_s % (ncase, str('IMPOSSIBLE'))
        return
    N = 2**(B-2) - M
    print 'N', N
    ine = [1] * (B-2)
    for i in xrange(B-2):
        if (N >> i) & 1 == 1:
            ine[i] = 0
    print ine
    print >>outputfile, out_s % (ncase, str('POSSIBLE'))
    print >>outputfile, '0' + ''.join(str(i) for i in ine) + '1'
    for j in xrange(B-2):
        print >>outputfile, '0' + '1'*j + '0' * (B-j-2) + '1'
    print >>outputfile, '0'*B
    

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    
