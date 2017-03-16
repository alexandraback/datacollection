def sumall(coins, target, current=[]):
    total = sum(current)
    if total == target:
        return True
    if total >= target:
        return False
    for index, coin in enumerate(coins):
        remaining = coins[index + 1:]
        if sumall(remaining, target, current + [coin]) is True:
            return True
    return False


def testValues(nbSameCoins, target, coins):
    added = 0
    for value in range(1, target + 1):
        if sumall(coins, value) is False:
            coins.append(value)
            added += 1
            # print("Adding ", value, coins)
    return added

nbcases = int(raw_input())

for numcase in range(nbcases):
    C, D, V = map(int, raw_input().split())
    values = map(int, raw_input().split())
    answer = testValues(C, V, values)
    print('Case #{0}: {1}'.format(numcase + 1, answer))
