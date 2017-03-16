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

def solve(N, K):


    N.sort()
    K.sort()
    n_bak = N[:]
    k_bak = K[:]
    log("Sorted\nN={}\nK={}".format(N, K))

    log("* war begins")
    warScore = 0
    while len(N)>0:
        nc = N.pop(0)
        log("Naomi chooses: {}".format(nc))
        # find the minimum greater in K
        kc = K[0]
        for i in range(len(K)):
            if K[i] > nc:
                kc = K[i]
                break
        K.remove(kc)
        if kc < nc:
            log("Ken can't find a better item, remove {}".format(kc))
            warScore += 1
        else:
            log("Ken uses {}".format(kc))

    N = n_bak
    K = k_bak

    log("* Deceitful War begins")
    dwScore = 0
    maxK = K[-1]
    maxN = N[-1]
    bluff = (maxN if maxN > maxK else maxK)

    while len(N)>0:
        minK = K[0]
        nc = N[0]
        # try to find a greater than minK
        for i in range(len(N)):
            if N[i] > minK:
                nc = N[i]
                break
        N.remove(nc)
        log("Naomi chooses {}".format(nc))
        if nc > minK:
            bluff += 1
            log("Naomi tells {}".format(bluff))
            K.remove(minK)
            log("Ken chooses {}".format(minK))
            dwScore += 1
        else:
            break





    return "{} {}".format(dwScore, warScore)
    
    
    
################################################################################
# main

if __name__ == '__main__':
    import sys
    r = sys.stdin.readline
    cases = int(r())
    for c in xrange(cases):
        log(case=c+1)
        int(r())
        N = map(float, r().split())
        K = map(float, r().split())
        print 'Case #{}: {}'.format(c + 1, solve(N, K))
