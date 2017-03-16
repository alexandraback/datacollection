import itertools
from collections import Counter


def read_ints():
    return map(int, input().strip().split())


def test_case(A, B, C, k):
    used_combinations = Counter()
    correct = []
    for outfit in itertools.product(list(range(1, A + 1)), list(range(1, B + 1)), list(range(1, C + 1))):
        a, b, c = outfit
        combinations = [(a, b, None), (a, None, c), (None, b, c)]
        wrong = False
        for comb in combinations:
            if used_combinations[comb] >= k:
                wrong = True
        if not wrong:
            correct.append(outfit)
            for comb in combinations:
                used_combinations[comb] += 1
    return correct


def main():
    T, = read_ints()
    for t in range(T):
        A, B, C, k = read_ints()
        out = test_case(A, B, C, k)
        print("Case #{}: {}".format(t + 1, len(out)))
        print('\n'.join("{} {} {}".format(*t) for t in out))

main()