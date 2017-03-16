import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        smax, counts = f.readline().strip().split()
        smax = int(smax)
        
        required = 0
        standing = 0
        for i in xrange(smax+1):
            if int(counts[i]) >= 1 and standing < i:
                demand = i - standing
                required += demand
                standing += demand
            standing += int(counts[i])
        
            
        print "Case #%d: %d" % (caseno+1, required)
        
main()