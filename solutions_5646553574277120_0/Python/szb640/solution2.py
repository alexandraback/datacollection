__author__ = 'bszikszai'

from io import *
#import sys
#sys.setrecursionlimit(1050)

def simulate(c, d, v, a):
    coins = a
    currentPossible = 0
    currentDenom = 0
    required = 0
    while(currentPossible < v):
        nextPossible = currentPossible + 1
        nextCoin = coins[0] if len(coins) > 0 else -1
        if(nextCoin >= nextPossible or nextCoin == -1):
            if (nextPossible in coins):
                coins.remove(nextPossible)
                currentPossible += c * nextPossible
            else:
                currentPossible += c * nextPossible
                required += 1
        else:
            currentPossible += c * nextCoin
            coins.remove(nextCoin)
    return required

def solve(f):
    inp = [int(x) for x in f.readline().rstrip('\n').rstrip('\r').split(' ')]
    inp2 = [int(x) for x in f.readline().rstrip('\n').rstrip('\r').split(' ')]
    return simulate(inp[0], inp[1], inp[2], inp2)

with open('input.txt', 'r') as f:
    with open('output.txt', 'wb') as g:
        cases = int(f.readline())
        for i in range(0, cases):
            solution = solve(f)
            print "Case #%s: %s" % (i+1, solution)
            g.write("Case #%s: %s\n" % (i+1, solution))