import sys, random

import psyco; psyco.full()


def decide(X, R, C):
    # False = Richard wins (not possible to cover)
    
    R, C = max(R, C), min(R, C)
    
    if X >= 7:
        return False    # Richard can create a piece with one open space enclosed, always
        
    if X > R:
        return False    # Richard can pick a long piece to win
    
    if (R*C) % X != 0:
        return False    # not possible to cover fully
        
    if X == 1 or X == 2:
        return True     # Only one possible piece, which fits all combinations
        
    if X == 3:
        return C != 1   # Richard can create a "L" piece which doesn't fit in a single column
        
    if X == 4:
        if C <= 2:      
            return False    # Richard can create a "T" piece, which is too big to fit one column, and blocks two columns into uncoverable pieces
        else:
            return True
        
    if X == 5:
        if C <= 3:
            return False    # Richard can create a "W" piece
        else:
            return True
            
    if X == 6:
        if C <= 3:
            return False    # Richard can create a "cross" piece
        else:
            return True
            
    print "Ambiguous X=%d  R=%d  C=%d" % (X, R, C)
    return None
      
def main():

    # for X in xrange(1, 21):
        # for R in xrange(1, 21):
            # for C in xrange(1, 21):
                # decide(X, R, C)
    # exit()
    
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        X, R, C = [int(n) for n in f.readline().split()]
        
        if decide(X, R, C):
            res = "GABRIEL"
        else:
            res = "RICHARD"
       
        print "Case #%d: %s" % (caseno+1, res)
        
main()