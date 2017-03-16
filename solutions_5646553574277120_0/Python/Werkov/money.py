import sys

def can_pay(coins, v):
    for mask in range(2**len(coins)):
        s = sum(c for i, c in enumerate(coins) if mask & (0x1 << i))
        if s == v:
            return True
    return False

def unpayable(coins, V):
    return [v for v in range(1, V+1) if not can_pay(coins, v)]

def solve(C, V, coins):
    if C > 1 or V > 30 or len(coins) > 5:
        return -1

    res = 0
    unp = unpayable(coins, V)
    while len(unp) > 0:
        unp.sort()
        #print(coins, unp)
        coins.append(unp[0])
        unp = unpayable(coins, V)
        res += 1

    return res
   

T = int(sys.stdin.readline().strip())
for t in range(T):
        C,D,V = [int(x) for x in sys.stdin.readline().strip().split()]
        coins = [int(x) for x in sys.stdin.readline().strip().split()]
        coins.sort()
        res = solve(C,V,coins)
        print("Case #{}: {}".format(t+1, res))
