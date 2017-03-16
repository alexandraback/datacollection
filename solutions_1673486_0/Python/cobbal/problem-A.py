#!/usr/bin/python

from decimal import Decimal
import operator

def keepGoing(A, B, probs):
    p = reduce(operator.mul, probs)
    keysIfGood = (B - A) + 1
    keysIfBad = keysIfGood + (B + 1)
    return p * keysIfGood + (1 - p) * keysIfBad

def backspaceN(A, B, probs, n):
    p = reduce(operator.mul, probs[:-n], 1)
    keysIfGood = n + n + (B - A) + 1
    keysIfBad = keysIfGood + (B + 1)
    return p * keysIfGood + (1 - p) * keysIfBad

def giveUpNow(A, B, probs):
    return B + 2

def allThe(A, B, probs):
    yield keepGoing(A, B, probs)
    for i in range(1, A + 1):
        yield backspaceN(A, B, probs, i)
    yield giveUpNow(A, B, probs)

def solve(A, B, probs):
    return min(allThe(A, B, probs))

T = int(raw_input())
for i in range(T):
    A, B = map(Decimal, raw_input().split())
    probs = map(Decimal, raw_input().split())
    print "Case #%i: %s" % (i+1, solve(A, B, probs))

