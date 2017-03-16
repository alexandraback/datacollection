def solve(C, D, V, coins):
    def get_candidates(V, coins):
        payable = set()
        for c in coins:
            tmp = set()
            for m in payable:
                tmp.add(c+m)
            tmp.add(c)
            payable = payable.union(tmp)

        noway = [c for c in range(1, V+1) if c not in payable]
        newcoins = []
        for c in noway:
            candidate = set()
            candidate.add(c)
            for m in range(1, c+1):
                if c-m in payable and m not in coins:
                    candidate.add(m)
            newcoins.append(candidate)
        return newcoins

    def search(coins, count):
        candidates = get_candidates(V, coins)
        if not candidates:
            return count
        return min(search(coins+[c], count+1) for c in min(candidates, key=len))

    return search(coins, 0)


for case in range(int(input())):
    C, D, V = map(int, input().split())
    coins = list(map(int, input().split()))
    print("Case #%d: %s" % (case+1, solve(C, D, V, coins)))

