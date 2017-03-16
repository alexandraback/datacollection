import sys
import itertools


def calc_purchasable_patterns(coins, v):
    purchasable = {0}
    for use in range(1, len(coins) + 1):
        pattern = itertools.combinations(coins, use)
        for used_coins in pattern:
            s = sum(used_coins)
            if s <= v:
                purchasable.add(sum(used_coins))

    return purchasable

# This is optimized for small. Consider c is always 1.
def solve_case(c, v, coins, case_number):
    purchasable = calc_purchasable_patterns(coins, v)

    rest = set(range(1, v + 1)) - purchasable

    possible_new_coins = set()
    for r in rest:
        for pr in range(1, r + 1):
            if pr in coins:
                continue
            if r in map(lambda x: x + pr, purchasable):
                possible_new_coins.add(r)

    new_denominations = 0
    for adoption in range(1, len(possible_new_coins) + 1):
        pattern = itertools.combinations(possible_new_coins, adoption)
        for adopt_coins in pattern:
            new_coins = coins + list(adopt_coins)
            new_purchasable = calc_purchasable_patterns(new_coins, v)
            if len(new_purchasable) == v + 1:
                new_denominations = adoption
                break
        else:
            continue
        break

    print "Case #%d: %d" % (case_number, new_denominations)

def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        cdv = map(int, r.readline().strip().split(' '))
        coins = map(int, r.readline().strip().split(' '))

        solve_case(cdv[0], cdv[2], coins, case_number)


if __name__ == '__main__':
    main()
