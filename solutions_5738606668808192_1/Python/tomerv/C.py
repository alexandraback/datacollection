import math
import random

def find_divisor(n):
    for i in range(2, int(math.sqrt(n))+1):
        if (n // i) * i == n:
            return i
    return None

def find_small_divisor(n):
    for i in range(2, min(int(math.sqrt(n))+1, 20)):
        if (n // i) * i == n:
            return i
    return None

def interpret(coin, base):
    res = 0
    mult = 1
    while coin:
        if coin[-1] == '1':
            res += mult
        coin = coin[:-1]
        mult *= base
    return res

def get_divisors(coin):
    interpretations = [interpret(coin, base) for base in range(2,11)]
    return list(map(find_divisor, interpretations))

def get_small_divisors(coin):
    interpretations = [interpret(coin, base) for base in range(2,11)]
    return list(map(find_small_divisor, interpretations))

def is_valid(coin):
    divisors = get_divisors(coin)
    return all(map(lambda x: x is not None, divisors))

n = 32
j = 500
coins = set()
print('Case #1:')
while len(coins) != j:
    coin = '1'
    for i in range(1,n-1):
        coin += random.choice('01')
    coin += '1'
    # print('(checking {})'.format(coin))
    divisors = get_small_divisors(coin)
    if all(map(lambda x: x is not None, divisors)):
        print('{} {}'.format(coin, ' '.join(map(str, divisors))))
        coins.add(coin)
