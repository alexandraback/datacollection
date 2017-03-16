import sys

import psyco; psyco.full()

def is_pal(n):
    s = str(n)
    
    ls = len(s)
    
    for i in xrange(ls/2+1):
        if s[i] != s[ls-1-i]:
            return False
            
    return True

def main():
    known = []
    for i in xrange(0, 10000001):
        if is_pal(i) and is_pal(i*i):
            known.append(i*i)
        
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        lo, hi = f.readline().strip().split()
        lo = int(lo)
        hi = int(hi)
        
        count = 0
        for n in known:
            if n >= lo and n <= hi:
                count += 1
        
            
        print "Case #%d: %d" % (caseno+1, count)
        
main()