import sys
from itertools import combinations

def get_value(selector, coins):
    result = 0
    for i in range(len(coins)):
        if selector % 2:
            result += coins[i]
        selector = int(selector / 2)
    return result

def run_test(case_number, generator):
    c, d, v = [int(x) for x in next(generator).split()]
    coins = [int(x) for x in next(generator).split()]

    possible_coins = []
    for i in range(v):
        value = i + 1
        if value not in coins:
            possible_coins.append(value)

    for size in range(len(possible_coins) + 1):
        if size:
            new_coins = []
            for comb in combinations(possible_coins, size):
                new_entry = coins[:]
                new_entry += comb
                new_coins.append(new_entry)
        else:
            new_coins = [coins]
        for new_coin in new_coins:
            values = {}
            maximum = 1 << len(new_coin)
            for i in range(maximum):
                value = get_value(i, new_coin)
                if value not in values:
                    values[value] = i

            missing = []
            for i in range(v):
                value = i + 1
                if value not in values:
                    missing.append(value)

            if not missing:
                print('Case #%d: %d' % (case_number, size))
                return
    print('Case #%d: ERROR' % case_number)

def main():
    generator = get_file()
    number_of_tests = int(next(generator))
    for test in range(1, number_of_tests + 1):
        run_test(test, generator)

def get_file():
    for line in sys.stdin:
        yield line
        
if __name__ == '__main__':
    main()