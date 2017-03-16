#!/usr/bin/env python3

from itertools import combinations

def make_table(value, coins):
    table = [None for _ in range(value+1)]
    table[0] = NotImplemented
    for size in range(1, len(coins)+1):
        for take in combinations(coins, size):
            try:
                table[sum(take)] = True
            except IndexError:
                pass
    return table

def extend_table(new_coin, table):
    for index, can_combine in enumerate(table):
        if can_combine:
            try:
                table[index+new_coin] = True
            except IndexError:
                pass
    return table

def devide_conqure(value, coins, table):
    memo = []
    for added in range(1, value+1):
        if added not in coins:
            memo += [(coins|{added}, extend_table(added, table[:]))]
    if not any(all(candit_table) for _, candit_table in memo):
        return min(devide_conqure(value, candit_coins, candit_table) for candit_coins, candit_table in memo)
    return min(len(candit_coins) for candit_coins, candit_table in memo if all(candit_table))

def comply_queen(value, coins):
    table = make_table(value, coins)
    if all(table):
        return 0
    return devide_conqure(value, coins, table) - len(coins)

for case in range(int(input())):
    _, _, value = [int(n) for n in input().split()]
    coins = {int(n) for n in input().split()}
    answer = comply_queen(value, coins)
    print('Case #{}: {}'.format(case+1, answer))
