import sys

import psyco; psyco.full()

def paint_for_size(n):
    return (n * (n+1)) / 2
        
def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        a, b = f.readline().split()
        r = int(a)
        t = int(b)
        
        available = t + paint_for_size(r - 1)
        
        low = 1
        high = 1000000000000000000001L
        
        while low < high - 1:
            average = (low + high) / 2
            #print low, high
            used = paint_for_size(r - 1 + (average * 2)) - paint_for_size(r - 1)
            if used <= t:
                low = average
            else:
                high = average
        
        print "Case #%d: %d" % (caseno+1, low)
main()