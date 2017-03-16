from collections import deque
import sys

def solve(c, init_coins, v):
    assert c == 1
    queue = deque([[]])
    while True:
        coins = queue.popleft()
        if check_coins(init_coins + coins, v):
            return len(coins)
        try:
            start = coins[-1] + 1
        except:
            start = 1
        for new_coin in xrange(start, v + 1):
            queue.append(coins + [new_coin])

def check_coins(coins, limit):
    coins = list(coins)
    if sum(coins) < limit:
        return False
    for amount in xrange(1, limit + 1):
        if not check_knapsack(coins, amount):
            return False
    return True

def check_knapsack(coins, amount, offset=0):
    if amount == 0:
        return True
    if amount < 0:
        return False
    if len(coins) == offset:
        return False
    left = check_knapsack(coins, amount - coins[offset], offset + 1)
    if left:
        return left
    right = check_knapsack(coins, amount, offset + 1)
    return right

if __name__ == "__main__":
    case_count = int(raw_input())
    for case_num in xrange(1, case_count + 1):
        c, d, v = [int(i) for i in raw_input().split()]
        coins = [int(i) for i in raw_input().split()]
        print "Case #%s: %s" % (case_num, solve(c, coins, v))
        sys.stdout.flush()
