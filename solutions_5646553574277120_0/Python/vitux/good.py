from itertools import combinations


def check(curr, v):
    x = [0] * (v + 1)
    x[0] = 1
    for i in curr:
        for j in range(v + 1)[::-1]:
            if x[j] and j + i <= v:
                x[j + i] = 1
    return not (0 in x)


if __name__ == '__main__':
    t = int(raw_input())
    for case in xrange(t):
        c, d, v = [int(i) for i in raw_input().split()]
        coins = [int(i) for i in raw_input().split()]
        req = range(1, v + 1)
        for coin in coins:
            req.remove(coin)
        ans = -1
        if check(coins, v):
            ans = 0
        for j in xrange(1, 6):
            if ans != -1:
                break
            for comb in combinations(req, j):
                if check(coins + list(comb), v):
                    ans = j
                    break
        print "Case #{}: {}".format(case + 1, ans)