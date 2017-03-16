import sys
import itertools
import math
import collections
import functools
import string

sys.setrecursionlimit(1000)

fact = [1]
for i in range(1, 105):
    fact.append(fact[i-1] * i)

def solve(words):

    # All the letters that appear in the middle of some word
    mid = []

    pivots = dict()
    chain = dict()
    inChain = dict()
    isEnd = dict()
    isStart = dict()
    for l in string.lowercase:
        pivots[l] = 0
        inChain[l] = False
        isEnd[l] = False
        isStart[l] = False

    for w in words:
        start = w[0]
        end = w[-1]
        prev = start
        hasEnd = False
        hasMid = False
        for l in w[1:-1]:
            if l == prev:
                continue
            prev = l
            if hasEnd:
                return 0
            if l == end:
                hasEnd = True
            else:
                hasMid = True
                mid.append(l)

        if start == end:
            if hasMid:
                return 0
            pivots[start] += 1
        elif start in chain:
            return 0
        else:
            chain[start] = end
            inChain[start] = True
            inChain[end] = True
            isEnd[end] = True
            isStart[start] = True

    for l in mid:
        if inChain[l]:
            return 0

    pieces = []
    done = dict()
    for s,e in chain.iteritems():
        done[s] = False

    # How many pieces can move around?
    for s,e in chain.iteritems():
        if isEnd[s]:
            # We cannot start a piece by this one
            continue
        done[s] = True
        c = fact[pivots[s]] * fact[pivots[e]]
        while isStart[e]:
            s = e
            done[s] = True
            e = chain[s]
            c *= fact[pivots[e]]
        pieces.append(c)

    for s,d in done.iteritems():
        if not d:
            return 0

    # What about pure pivots?
    for l,c in pivots.iteritems():
        if c > 0 and not inChain[l]:
            pieces.append(fact[c])

    # Ok, let's piece everything together
    tot = 1
    for p in pieces:
        tot *= p
    return tot * fact[len(pieces)]
        
        
    

T = int(raw_input())
for testId in range(T):
    N = int(raw_input())
    words = raw_input().split()

    res = solve(words)
    res = res % 1000000007

    print "Case #{:d}: {:d}".format(testId+1, res)
