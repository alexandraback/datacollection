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

    if N == 0:
        print >>outputfile, out_s % (ncase, "INSOMNIA")
        return

    digs_seen = [False] * 10
    num_unseen = 10
    i = 1
    while 1:
        cur_N = i * N
        num = cur_N
        while num > 0:
            dig = num % 10
            if digs_seen[dig] == False:
                num_unseen -= 1
            digs_seen[dig] = True
            num /= 10
        if num_unseen == 0:
            print >>outputfile, out_s % (ncase, str(cur_N))
            return
        i += 1
    
    

start_time = time.time()
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    print "Doing case", ncase
    do_case(ncase)
    print "Done, time", time.time()-start_time
    