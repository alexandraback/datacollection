import math, sys
from collections import Counter


def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine


def main():

    def nextDuplicates(c):
        dupl_c = dict()
        sorted_ind_c = sorted(range(len(c)), key=lambda x: c[x])
        for i in xrange(len(c) - 1):
            if c[sorted_ind_c[i]] == c[sorted_ind_c[i+1]]:
                dupl_c[ sorted_ind_c[i] ] = sorted_ind_c[i+1]
        return dupl_c

    def countOverlap(teststr):
        n = nextDuplicates(teststr)
        if len(n) == 0:
            return 0

        L = len(teststr)
        maxOverLap = 0
        for i in xrange(1, L):
            s = teststr[0:i]            
            if s == teststr[-i:]:
                maxOverLap = i
        #print "mo", maxOverLap, teststr, s, teststr[-i:]
        return maxOverLap

    def solve(K, L, S, keyboard, target):
        setSrc = set(keyboard)
        setTarget = set(target)
        setDiff = setTarget - setSrc
        if len(setDiff):
            return 0.0
        if len(setSrc) == 1 and len(setTarget) == 1:
            return 0.0

        counterSrc = Counter(keyboard)
        #counterTarget = Counter(target)
        overlap = countOverlap(target)
        maxBananas = 1 + (S-L) / (L-overlap)
        rest = maxBananas

        chance1 = 1.0
        for l in setTarget:
            chance1 *= counterSrc[l]*1.0 / K
        return maxBananas*(1.0 - chance1)

    ############################################1
    T = int( raw_input() )
    for t in xrange(T):            
        K, L, S = map( int, raw_input().split(' ') )        
        keyboard = raw_input()
        target = raw_input()
        output( t, solve(K, L, S, keyboard, target) )


if __name__ == "__main__":
   main()