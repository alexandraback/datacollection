from copy import copy
from itertools import combinations

def addcoin(coin, canmake):
    for i in xrange(len(canmake)-1, -1, -1):
        if i - coin >= 0:
            canmake[i] = canmake[i] or canmake[i-coin]

def differences(canmake):
    d = dict([(i, 0) for i in xrange(len(canmake))])
    for i in xrange(len(canmake)):
        for j in xrange(i):
            if canmake[j] and not canmake[i]:
                d[i-j] += 1
    return d

def bestcoin(d):
    print d
    bc, bval = 0, 0
    for c, val in d.iteritems():
        if val > bval:
            bc, bval = c, val
        elif val == bval and c < bc:
            bc = c
    return bc
            
def solvesmall(case):
    count = 0
    _, v, coins = case
    canmake = [True] + [False] * v
    for coin in coins:
        addcoin(coin, canmake)
    while not min(canmake):
        d = differences(canmake)
        for coin in coins:
            del d[coin]
        c = bestcoin(d)
        addcoin(c, canmake)
        count += 1
    return count

def solvesmall2(case):
    _, v, coins = case
    canmake = [True] + [False] * v
    for coin in coins:
        addcoin(coin, canmake)
    if min(canmake):
        return 0
    else:
        coinsleft = set(range(v+1)).difference(coins)
        for i in range(1, 6):
            for newcoins in combinations(coinsleft, i):
                trial = copy(canmake)
                for coin in newcoins:
                    addcoin(coin, trial)
                if min(trial):
                    print newcoins
                    return i
        assert False

def maxachievable(maxcoin, coins, c):
    return c * sum(filter(lambda coin: coin <= maxcoin,
                          coins))

def solve(case):
    c, v, coins = case
    print case
    coins.sort()
    count = 0
    if 1 not in coins:
        count += 1
        coins.append(1)
        coins.sort()
        print "1added"
    maxcoin = 1 #max coin we've analyzed
    while maxachievable(maxcoin, coins, c) < v:
        #is there a valid coin under maxachievable?
        ma = maxachievable(maxcoin, coins, c)
#        print maxcoin, coins, ma
        considerable = [coin for coin in coins if maxcoin < coin <= ma+1]
        if len(considerable) != 0:
            maxcoin = max(considerable)
        else:
            newcoin = ma + 1
            maxcoin = newcoin
            coins.append(newcoin)
            coins.sort()
            count += 1
            print "new"
    return count

f = open('c.in', 'r')
lines = f.readlines()

cases = []

for i in xrange(int(lines[0])):
    vals = map(int, list(lines[2*i + 1].split()))
    coins = map(int, list(lines[2*i + 2].split()))
    case = [vals[0], vals[2], coins]
    cases.append(case)


g = open('c.out','w')
for i in xrange(len(cases)):
    g.write('Case #' + str(i + 1) + ': ' + str(solve(cases[i])) + '\n')
g.close()
