from Solve import *
from itertools import combinations
from sets import Set
 
def money(args):
    c, d, v = [int(e) for e in args[0].split(" ")]
    denoms = [int(e) for e in args[1].split(" ")][::-1]
    
    vals = range(1, v+1)
    sums = Set([0])
    for r in xrange(1, d + 1): 
        for c in combinations(denoms, r):
            s = sum(c)
            sums.add(s)
            if s in vals:
                vals.remove(s)
                if not vals:
                    return 0

    nAdded = 0
    for val in vals:
        if not val in sums:
            nAdded+=1
            newSums = Set([s + val for s in sums])
            sums = sums | newSums
        
    return nAdded
    
solveF("F:\ProgramiranjeOstalo/GCJ/1c_2015/C-small-attempt1.in", money, 2)