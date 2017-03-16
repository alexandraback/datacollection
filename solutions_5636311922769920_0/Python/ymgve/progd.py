import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        K, C, S = f.readline().strip().split()
        K = int(K)
        C = int(C)
        S = int(S)
        
        res = " ".join(list((str(x+1) for x in range(K))))
        print "Case #%d: %s" % (caseno+1, res)
        
main()