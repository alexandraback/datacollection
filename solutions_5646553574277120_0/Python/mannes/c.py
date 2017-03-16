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
                    return i
        assert False


f = open('c.in', 'r')
lines = f.readlines()

cases = []

for i in xrange(int(lines[0])):
    vals = map(int, list(lines[2*i + 1].split()))
    coins = map(int, list(lines[2*i + 2].split()))
    case = [vals[0], vals[2], coins]
    cases.append(case)
print cases

g = open('c.out','w')
for i in xrange(len(cases)):
    g.write('Case #' + str(i + 1) + ': ' + str(solvesmall2(cases[i])) + '\n')
g.close()
