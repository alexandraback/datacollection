import fileinput 
from math import ceil

def do_case(case_num):
    D = int(next(input))
    P = [int(x) for x in next(input).split(' ')]
    print "D: %d, P: %s" % (D, P)
    n = 0
    min_took = 1000000000000
    while True:
        n += 1
        took = n + sum([ int(ceil((p - n) / float(n))) for p in P ])
        print "n: %d, took: %d" % (n, took)
        if took < min_took:
            min_took = took
        if min_took < n:
            print "Case #%d: %d" % (case_num, min_took)
            return
    assert(False)
        
input = fileinput.input()
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

