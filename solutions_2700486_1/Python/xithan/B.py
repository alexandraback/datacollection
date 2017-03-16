#!/usr/local/Cellar/python3/3.2.2/bin/python3

from GCJ import GCJ
import math


def choose(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0
        

        
def pyramid_size(sp):
    return ((2*sp-1)*(2*sp)) // 2

def solve(infile):
    N, X, Y  = GCJ.readints(infile)
    if  (X+Y) % 2 == 1: # keine Mitte landet hier
        return 0.0
    
    if X == 0 and Y == 0:
        return 1.0   
    # Unterpyramide berechnent
    sp = ((abs(X) + abs(Y)) // 2)
    
    min_pieces = pyramid_size(sp)
    if min_pieces >= N:
        return 0.0
    
    rest = N - min_pieces
    next_layer = pyramid_size(sp+1) - min_pieces
    one_side = (next_layer - 1) // 2
    allowed_fails = rest - Y
    if rest >= next_layer or rest >= (one_side + Y + 1):
        return 1.0
    if X == 0 and rest < next_layer:
        return 0.0
    else:
        summe = 0        
        for i in range(Y+1):
            summe += choose(rest,i)# * (0.5 ** rest)
        return 1 - (summe / (2**rest))
            


if __name__ == "__main__":
    GCJ("B",solve).run()