import sys, heapq

import psyco; psyco.full()

def solve(j, p, s, k):
    jp = {}
    js = {}
    ps = {}
    outfits = []
    
    for jj in xrange(1,j+1):
        for pp in xrange(1, p+1):
            for ss in xrange(1, s+1):
                outfit = "%d %d %d" % (jj, pp, ss)
                    
                if (jj, pp) in jp and jp[(jj, pp)] >= k:
                    continue
                if (jj, ss) in js and js[(jj, ss)] >= k:
                    continue
                if (pp, ss) in ps and ps[(pp, ss)] >= k:
                    continue
                    
                outfits.append(outfit)
                if (jj, pp) not in jp:
                    jp[(jj, pp)] = 0
                jp[(jj, pp)] += 1
                
                if (jj, ss) not in js:
                    js[(jj, ss)] = 0
                js[(jj, ss)] += 1
                
                if (pp, ss) not in ps:
                    ps[(pp, ss)] = 0
                ps[(pp, ss)] += 1

    return outfits
    
def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        j, p, s, k = [int(x) for x in f.readline().strip().split()]
        
        res = solve(j, p, s, k)
            
        print "Case #%d: %d" % (caseno+1, len(res))
        for r in res:
            print r
        
main()