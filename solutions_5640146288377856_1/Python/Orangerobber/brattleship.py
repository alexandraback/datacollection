import sys
from math import sqrt, floor

T = int(sys.stdin.readline())

for t in range(T):
    R, C, W = [int(x) for x in sys.stdin.readline().split()]

    g = 0
    #take each row in term
    #guess from the left until
    g += (R-1)*floor(float(C)/ W)

    #on final row, must have guessed the ship

    while(C >= 2*W):
        C -= W
        g += 1

    #now we know that ship is in remaining C squares
    g += W
    if(C>W):
        g += 1
        
    print "Case #%d: %d"%(t+1 , g)