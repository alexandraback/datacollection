import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        s = f.readline().strip()
        s += "+"
        
        flips = 0
        for i in xrange(len(s)-1):
            if s[i] != s[i+1]:
                flips += 1
        
        print "Case #%d: %d" % (caseno+1, flips)
        
main()