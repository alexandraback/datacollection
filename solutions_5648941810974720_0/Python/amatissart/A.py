# -*- coding: utf-8 -*-
import sys
from collections import Counter

digits =  ((6,"SIX"),(0,"ZERO"), (8,"EIGHT"), (2,"TWO"),
     (4,"FOUR"),(3,"THREE"), (5,"FIVE"), (7,"SEVEN"), (9,"NINE"), (1,"ONE"))

def isin(number, digit):
    dc = Counter(digit)
    for c in dc:
        if number[c] < dc[c]:
            return False
    return True

filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for j in xrange(n_cases):
        c = Counter()
        c.update(f.readline().strip())
        res = []
        for i, d in digits:
            while isin(c, d):
                res.append(str(i))
                c.subtract(d)
        res = "".join(sorted(res))
        print 'Case #{t}: {r}'.format(t=j+1, r=res)
        
