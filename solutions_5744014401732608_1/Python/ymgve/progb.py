import sys

import psyco; psyco.full()

def consistent(parties):
    largest = 0
    total = 0
    for p, n in parties:
        largest = max(largest, p)
        total += p
        
    if largest * 2 > total:
        raise Exception("INCONSISTENT")
        
    return total
    
def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        b, m = [int(x) for x in f.readline().strip().split()]
     
        largest = 2**(b-2)
        if largest < m:
            print "Case #%d: IMPOSSIBLE" % (caseno+1)
        else:
            rows = []
            brep = bin(m)[2:]
            if largest != m:
                rows.append(brep.rjust(b-1, "0") + "0")
                for i in xrange(b-len(brep)-2):
                    rows.append("0" * b)
            for i in xrange(b-len(brep), b+1):
                rows.append("0" * i + "1" * (b-i))
            print "Case #%d: POSSIBLE" % (caseno+1)
            if len(rows) != len(rows[0]):
                raise Exception("BAD NUMBER OF ROWS")
                
            for row in rows:
                print row
        
        
main()