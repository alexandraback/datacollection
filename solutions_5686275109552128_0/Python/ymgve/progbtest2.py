import sys

import psyco; psyco.full()

def main():

    bestmoves = []

    sz = 1001
    for p in xrange(1, sz):
        bestmoves.append([10000000] * sz)
        for d in xrange(1, p+1):
            res = p / d
            if p % d != 0:
                res += 1
                
            moves = d - 1
            eats = res
            #print p, d, moves, eats, moves+eats
            bestmoves[p-1][eats-1] = min(bestmoves[p-1][eats-1], moves)
            
        for i in xrange(1, sz):
            if bestmoves[p-1][i] == 10000000:
                bestmoves[p-1][i] = bestmoves[p-1][i-1]

    # for b in bestmoves:
        # print b
        
    # exit()
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        ndiners = int(f.readline().strip())
        diners = []
        for p in f.readline().strip().split():
            diners.append(int(p))
        
        best = 10000000
        for numeats in xrange(1, sz):
            curr = 0
            for p in diners:
                curr += bestmoves[p-1][numeats-1]
                
            #print diners, numeats, curr
            best = min(best, curr + numeats)
            
        print "Case #%d: %d" % (caseno+1, best)
        
main()