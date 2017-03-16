#!/usr/bin/env python
import sys
from collections import Counter

    
l=("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
#
#l1=("ONE", "THREE", "FIVE", "SEVEN", "NINE")

#c = Counter()
#for i in l1:
#    c.update(i)
#
#print  c

dict1 = {}
for i in l:
    dict1[i] = Counter(i)

round1 = {'Z' : 'ZERO', 
          'X' : 'SIX', 
          'W' : 'TWO',
          'U' : 'FOUR',
          'G' : 'EIGHT'
}

round2 = { 'O': 'ONE',
    'T': 'THREE',
    'F': 'FIVE',
    'S': 'SEVEN',
}

def gd(letters):
    
    d = Counter()
    n = []
    for i in letters:
        d.update(i)

    for i in round1.keys():
        while d[i] > 0 :
            d.subtract( dict1[round1[i]] )
            n.append( l.index( round1[i] ) )

    for i in round2.keys():
        while d[i] > 0 :
            d.subtract( dict1[round2[i]] )
            n.append( l.index( round2[i] ) )

            
            
    for i in  range(d['N']/2):
        n.append(9)


    return ''.join(map(str, sorted(n) ) )


    


fin = open(sys.argv[1], 'r')
cases = int( fin.readline().strip() )
for i  in range(cases):
    letters = fin.readline().strip()
    print "Case #%d: %s" % ( i+1 , gd(letters) )
