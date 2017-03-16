for x in range(1, int(input()) + 1):
    C, D, V = map(int, input().split())
    d = map(int, input().split())
    poss = [1] + [0] * V
    def usecoin(coin):
        for value in range(V, coin-1, -1):
            poss[value] |= poss[value-coin]
    for coin in d:
        usecoin(coin)
    added = 0
    for value in range(1, V+1):
        if not poss[value]:
            usecoin(value)
            added += 1
    print('Case #%d:' % x, added)
