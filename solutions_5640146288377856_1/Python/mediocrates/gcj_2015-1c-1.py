import math
with open('A-large (1).in', 'r+b') as f:
    T = int(f.readline().strip())
    for i in range(1, T+1):
        R, C, W = map(int, f.readline().strip().split())
        totalToTry = 0
        numTryPerRowBeforeHit = int(math.ceil(C/W))
        totalToTry += numTryPerRowBeforeHit*R
        if C % W == 0:
            totalToTry += W-1
        else:
            totalToTry += min(W, C-1)
        print "Case #%d: %d" % (i, totalToTry)
