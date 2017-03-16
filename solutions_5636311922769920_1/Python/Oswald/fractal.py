import math

def getSpot(x, k, c, bitOff):
    currentSpot = 1
    for currentDepth in range(bitOff, min(c, k - x)):
        currentSpot += int(math.pow(k, c - 1 - currentDepth)) * (x + currentDepth)
        '''print "Depth %s" % (x + currentDepth)
        print "pow size %s" % int(math.pow(k, c - 1 - currentDepth))
        print "current x %s" % (x + currentDepth)
        print "spot %s" % currentSpot '''
    return currentSpot

def main():
    cases = int(raw_input())
    for case in range(1, cases + 1):
        k, c, s = [int(section) for section in raw_input().split(" ")]
        needed = None
        if c == 1:
            needed = k
        else:
            needed = int(math.ceil(float(k)/float(c)))
        neededLocations = []
        canDo = (s >= needed)
        grids = math.pow(k, c)
        #print (k, c, s)
        #print (case, canDo)
        if canDo:
            for rawX in range(0, k, c):
                x = rawX
                x = max(min(rawX, k - c), 0)
                offBy = rawX - x
                currentSpot = getSpot(x, k, c, offBy)
                if currentSpot > grids:
                    print "ERROR ERROR"
                    return
                neededLocations.append(currentSpot)
            if len(neededLocations) != needed or len(set(neededLocations)) != len(neededLocations):
                print "ERROR ERROR"
                return
        locationString = ' '.join([str(section) for section in neededLocations])
        print "Case #%s: %s" % (case, locationString if canDo else "IMPOSSIBLE")

main()