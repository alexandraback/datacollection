import sys
#import pdb
import numpy as np 

debug = 0


def solve(r, t):
    r= np.float128(r)
    t = np.float128(t)
    tmp= 1-2*r + np.sqrt( (2*r - 1) **2 + 8 *t  )
    return int( tmp/4.0 )

fin = open(sys.argv[1])
cases = int( fin.readline() ) 
for case in range(cases):
    
    r, t = map(int, fin.readline().split()  )

    solution = solve(r,t)
    
    #solution = ''
    print "Case #%d: %d" % (case+1, solution) 



