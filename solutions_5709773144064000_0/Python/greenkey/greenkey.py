#!/usr/bin/python

"""Usage:
    X.py < X.in > X.out
"""

################################################################################
# util functions

logging = False

globalCase = 0
def log(string="", case=0):
    global globalCase
    if logging:
        if case > 0:
            globalCase = case
            string = "started case - %s" % string
        print("Case #%d: %s" % (globalCase, string))

################################################################################
# problem functions

def solve(farmCost, farmRate, goal):
    log("farmCost={}, farmRate={}, goal={}".format(farmCost, farmRate, goal))
    timeSpent = 0
    rate = 2.0
    minTime = goal/rate
    log("minTime: {}".format(minTime))
    while True:
        # buy a farm
        timeSpent += farmCost/rate # track time spent for earning cookies for farm
        rate += farmRate # increment rate
        # calculate new minTime
        newMinTime = goal/rate + timeSpent
        log("newMinTime: {}".format(newMinTime))
        if newMinTime < minTime:
            minTime = newMinTime
        else:
            return minTime
    
################################################################################
# main

if __name__ == '__main__':
    import sys
    r = sys.stdin.readline
    cases = int(r())
    for c in xrange(cases):
        log(case=c+1)
        #single = int(r())
        (C, F, X) = map(float, r().split())
        print 'Case #{}: {}'.format(c + 1, solve(C, F, X))
