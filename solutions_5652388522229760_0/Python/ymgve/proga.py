import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        n = int(f.readline().strip())

        seen = {}
        last = None
        for j in xrange(1, 1000000):
            for c in str(n * j):
                seen[c] = True
                
            if len(seen) == 10:
                last = n * j
                break
                
        if last is None:
            res = "INSOMNIA"
        else:
            res = str(last)
            
        print "Case #%d: %s" % (caseno+1, res)
        
main()