import sys

inp = sys.stdin

T = int(inp.readline())

for testCase in xrange(1,T+1):
    E, R, N = map(lambda x: int(x), inp.readline().split(" "))
    gains = map(lambda x: int(x), inp.readline().split(" "))
    gainsPeaks = [0]*(len(gains))

    for i in xrange(len(gains)):
        betterFound = False
        for j in xrange(i+1, len(gains)):
            if gains[j] > gains[i]:
                gainsPeaks[i] = j
                betterFound = True
                break
        if not betterFound:
            gainsPeaks[i] = -1

#    print E, R, N
 #   print gains
  #  print gainsPeaks
    currEnergy = E
    maxGain = 0

    for i in xrange(len(gains)):
        if gainsPeaks[i] == -1:
            maxGain += (gains[i]*currEnergy)
            currEnergy = R
       #     print "Spend all: {} at {}".format(currEnergy, i)
        else:
            toSpend = (((gainsPeaks[i]-i)*R)+currEnergy) - E
            if toSpend > 0:
                if toSpend > currEnergy:
                    toSpend = currEnergy
                maxGain += gains[i]*toSpend
                currEnergy -= toSpend
                currEnergy += R
        #        print "Spend some: {} at {}, {}".format(toSpend, i, currEnergy)
                
    
    print "Case #{}: {}".format(testCase, maxGain)

