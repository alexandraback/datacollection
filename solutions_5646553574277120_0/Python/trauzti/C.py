from itertools import combinations
T = int(raw_input())

# returns values, missing
def getValues(coins, C):
    #print "Coins=%s" % coins
    #print "V=%d" % V
    values = []
    valued = {}
    for count in xrange(1, len(coins)+1):
        for comb in combinations(coins, count):
            #print "comb=%s, sm=%d" % (comb, sum(comb))
            values.append(sum(comb))
            valued[sum(comb)] = 1
    values.sort()
    missing = []
    for v in xrange(1, V+1):
        if v not in valued:
            missing.append(v)

    return values, missing

"""
def bestCoinsToadd(coins, count, V):
    add = []
    val = 1
    while len(add) < count:
        if val in coins:
            val += 1
        else:
            add.append(val)
    return add
"""

def getMinCount(coins, C, V):
    cnt = 0
    while True:
        values, missing = getValues(coins, C)
        if not missing:
            return cnt
        cnt += 1
        coins += [min(missing)]
    """
    for addCoins in range(0, V):
        #add = bestCoinsToadd(coins, addCoins, V)
        pool = [z for z in range(1,V+1) if z not in coins]
        add = missing[:addCoins]
        valuesNow, missingNow = getValues(coins + list(add), C)
        if len(missingNow) == 0:
            #print "BREAK!!"
            return addCoins
    """

for tc in xrange(1, 1+T):
    C,D,V = map(int, raw_input().split())
    coins = map(int, raw_input().split())
    assert C == 1
    assert len(coins) == D
    units = []
    values, missing = getValues(coins, C)
    #print "values=%s" % values
    #print "missing=%s" % missing
    needToAdd = len(missing)
    needToAdd = getMinCount(coins, C, V)


    #print C,D,V,coins
    print "Case #%d: %d" % (tc, needToAdd)

