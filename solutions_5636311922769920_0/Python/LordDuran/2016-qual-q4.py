# from __future__ import division
from pprint import pprint
import time
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

def do_case(ncase):
    K, C, S = parse_line()
    assert K == S
    l = [n*K**(C-1)+1 for n in xrange(K)]
    print >>outputfile, out_s % (ncase, ' '.join(str(n) for n in l))

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    