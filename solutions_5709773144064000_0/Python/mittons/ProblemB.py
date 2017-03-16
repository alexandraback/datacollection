
def findTimeToReachReqCookies(currTime, currCookies, cps, reqCookies):
    cookiesWeNeed = reqCookies - currCookies
    reqTime = cookiesWeNeed/cps
    return reqTime + currTime
    

def findOptimalTime(testCaseValues):
    C = testCaseValues[0]
    F = testCaseValues[1]
    X = testCaseValues[2]
    currTime = 0.0
    currCookies = 0
    #cps = cookiesPerSecond
    cps = 2.0
    bestGoalTime = findTimeToReachReqCookies(currTime, currCookies, cps, X)
    factoryTime = findTimeToReachReqCookies(currTime, currCookies, cps, C)
    while bestGoalTime >= factoryTime:
        currTime = factoryTime
        cps += F
        goalTime = findTimeToReachReqCookies(currTime, currCookies, cps, X)
        factoryTime = findTimeToReachReqCookies(currTime, currCookies, cps, C)
        bestGoalTime = min(goalTime, bestGoalTime)
        
    return bestGoalTime

inp = open("B-small-attempt0.in", 'r')
outp = open("B-small-attempt0.out", 'w')
T = int(inp.readline())

for testCase in xrange(T):
    testCaseValues = map(lambda x: float(x), inp.readline()[0:-1].split(" "))
    outp.write("Case #{0}: {1:.7f}\n".format(testCase + 1, findOptimalTime(testCaseValues)))

outp.close()
