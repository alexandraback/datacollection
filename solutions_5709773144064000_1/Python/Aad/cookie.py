
from itertools import *
import sys

def main(f, case):
    C, F, X = map(float, f.readline().split())
    if X < C:
        print "Case #" + str(case) + ": {:.7f}".format(X/2.0)
        return
    r = 2.0
    t = X/r
    a = 0
    while True:
        if t < (C/r+X/(r+F)):
            break
        a += C/r
        r += F
        t = X/r
    print "Case #" + str(case) + ": {:.7f}".format(a + t)
    


with open(sys.argv[1]) as f:
    N = int(f.readline())
    for i in xrange(N):
        main(f, i+1)
