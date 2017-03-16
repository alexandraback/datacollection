import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        print "Case #%d:" % (caseno+1)
        a, b, c, d = f.readline().split()
        r = int(a)
        n = int(b)
        m = int(c)
        k = int(c)
        
        probs = {}
        keys = {}
        for a in xrange(2, 6):
         for b in xrange(2, 6):
          for c in xrange(2, 6):
           slist = [a, b, c]
           slist.sort()
           
           key = "%d%d%d" % tuple(slist)
           keys[key] = True
           
           for i in xrange(8):
            x = 1
            if i & 1 != 0:
                x *= a
            if i & 2 != 0:
                x *= b
            if i & 4 != 0:
                x *= c
        
            if x not in probs:
                probs[x] = []
            probs[x].append(key)
            
        
        
        for i in xrange(r):
            cand = keys.keys()
            for v in f.readline().split():
                newcand = []
                v = int(v)
                for pp in probs[v]:
                    if pp in cand and pp not in newcand:
                        newcand.append(pp)
                        
                cand = newcand
                
            print cand[0]

main()