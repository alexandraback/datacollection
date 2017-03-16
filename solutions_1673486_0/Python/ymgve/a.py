import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline().strip())
    
    for caseno in xrange(ncases):
        parts = f.readline().strip().split()
        sofar = int(parts[0])
        total = int(parts[1])
        
        probs = []
        parts = f.readline().strip().split()
        for i in xrange(sofar):
            probs.append(float(parts[i]))
                
        odds = 1.0
        best = 100000000000000000.0
        for deletes in xrange(sofar, -1, -1):
            if deletes != sofar:
                odds *= probs[sofar - deletes - 1]
                
            sgood = deletes + total + 1 - (sofar - deletes)
            sbad = sgood + total + 1
            
            
            res = odds * sgood + (1.0 - odds) * sbad
            if res < best:
                best = res
                
            
        wildcard = float(total + 2)
        if wildcard < best:
            best = wildcard
            
        print "Case #%d: %.6f" % (caseno+1, best)
main()