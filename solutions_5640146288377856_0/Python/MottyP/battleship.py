import sys

def findNumNeeded(R, C, W):
    if W==1:
        return R*C
    divs = C / (2*W+1)
    rem = C % (2*W+1)
    nblocks = (divs+1) * R
    blocksize = (C-divs) / nblocks
    m1 = -1 if blocksize==W else 0
    return nblocks + W + m1

def doMain():
    ncases = int(sys.stdin.readline())
    for cs in range(1, ncases+1):
        R, C, W = [int(part) for part in sys.stdin.readline().split()]
        numNeeded = findNumNeeded(R, C, W)
        print 'Case #%d: %s' % (cs, numNeeded)

if __name__ == "__main__":
    doMain()
