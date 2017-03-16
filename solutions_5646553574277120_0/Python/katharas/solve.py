
from itertools import combinations

def solve(C, D, V, denominations):
    def finished(prices, V):
        for p in xrange(1, V+1):
            if p not in prices:
                return False
        return True

    prices = set()
    for i in xrange(1, D+1):
        for c in combinations(denominations, i):
            prices.add(sum(c))
    denominations = set(denominations)

    if finished(prices, V):
        return 0

    possible_coins = list(set(range(1, V+1))-denominations)
    for i in xrange(1, len(possible_coins)+1):
        for c in combinations(possible_coins, i):
            prices2 = set(prices)
            for p in c:
                tempset = set()
                tempset.add(p)
                for x in prices2:
                    tempset.add(x+p)
                prices2 = prices2 | tempset
            if finished(prices2, V):
                return i

    return 0

T = int(raw_input())
for t in xrange(1, T+1):
   C, D, V = map(int, raw_input().split())
   denominations = map(int, raw_input().split())
   print "Case #%d: %d" % (t, solve(C, D, V, denominations))
