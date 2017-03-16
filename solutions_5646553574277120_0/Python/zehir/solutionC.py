import sys

def possiblevals(coins):
    if len(coins) == 0:
        return set([0])
    p = possiblevals(coins[1:])
    return p.union(set([x + coins[0] for x in p]))

def impossiblevals(coins, maxval):
    possible = possiblevals(coins)
    return set([x for x in range(1, maxval + 1) if x not in possible])

def missingcoins(coins, val):
    acc = []
    for possible in possiblevals(coins):
        if possible < val:
            acc.append(val - possible)
    return [x for x in acc if x not in coins]

def subsets(i, notcoins):
    if i == 0 or notcoins == []:
        return [[]]
    else:
        subsets1 = subsets(i - 1, notcoins[1:])
        return subsets1 + [l + [notcoins[0]] for l in subsets1]

def issol(subset, needed):
    acc = needed
    for i in subset:
        acc = [x for x in acc if i in x]
    return acc == []

def solution(coins, maxval):
    acc = []
    for impossible in impossiblevals(coins, maxval):
        missing = missingcoins(coins, impossible)
        acc.append(missing)
    notcoins = [x for x in range(1, maxval + 1) if x not in coins]
    for i in range(1, maxval):
        subsets1 = subsets(i, notcoins)
        for subset in subsets1:
            if issol(subset, acc):
                return len(subset)

with open(sys.argv[1]) as f:
    n = int(f.readline())
    for i in range(n):
        c, d, v = [int(x) for x in f.readline().split()]
        coins = [int(x) for x in f.readline().split()]
        print("Case #%d:" % (i + 1), solution(coins, v))
