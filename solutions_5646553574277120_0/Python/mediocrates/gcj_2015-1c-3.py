with open('C-small-attempt0.in', 'r+b') as f:
    T = int(f.readline().strip())
    for i in range(1, T+1):
        C, D, V = map(int, f.readline().strip().split())
        coins = map(int, f.readline().strip().split())
        # print "coins =", coins
        payables = [0]
        for c in coins:
            for p in payables[:]:
                if p+c not in payables:
                    payables.append(p+c)
        remaining = [p for p in range(1,V+1) if p not in payables]
        coinsToAdd = []
        # print "remaining = ", remaining
        while remaining != []:
            coinToAdd = remaining[0]
            coinsToAdd.append(coinToAdd)
            payablesToExtend = [r for r in remaining if r-coinToAdd in payables]
            remaining = [r for r in remaining[1:] if r-coinToAdd not in payables]
            payables.extend(payablesToExtend)

            # print remaining
        # print coinsToAdd
        print "Case #%d: %d" % (i, len(coinsToAdd))

