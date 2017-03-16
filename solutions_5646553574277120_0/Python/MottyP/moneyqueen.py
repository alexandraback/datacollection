import sys

def findNewNeeded(radix, existing, target):
    maxable = 0
    numNewNeeded = 0
    while maxable < target:
        nextNeeded = maxable + 1
        if existing and existing[0] <= nextNeeded:
            toUse = existing[0]
            del existing[0]
        else:
            toUse = nextNeeded
            numNewNeeded += 1
        maxable += toUse * (radix-1)
    return numNewNeeded

def doMain():
    ncases = int(sys.stdin.readline())
    for cs in range(1, ncases+1):
        radix, numExisting, target = [int(part) for part in sys.stdin.readline().split()]
        radix += 1
        existing = [int(part) for part in sys.stdin.readline().split()]
        assert len(existing) == numExisting
        newNeeded = findNewNeeded(radix, existing, target)
        print 'Case #%d: %s' % (cs, newNeeded)

if __name__ == "__main__":
    doMain()
