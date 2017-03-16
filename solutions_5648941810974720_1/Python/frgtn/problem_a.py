import sys
from collections import Counter


ZERO = Counter('ZERO')
ONE = Counter('ONE')
TWO = Counter('TWO')
THREE = Counter('THREE')
FOUR = Counter('FOUR')
FIVE = Counter('FIVE')
SIX = Counter('SIX')
SEVEN = Counter('SEVEN')
EIGHT = Counter('EIGHT')
NINE = Counter('NINE')

NUMBERS = {
    0: ZERO,
    1: ONE,
    2: TWO,
    3: THREE,
    4: FOUR,
    5: FIVE,
    6: SIX,
    7: SEVEN,
    8: EIGHT,
    9: NINE,
}

CHECK_ORDER = [0, 2, 4, 6, 8, 3, 1, 5, 7, 9]


def contains_number(S, counter):
    return all([S[c] >= count for c, count in counter.items()])


def solve(T, S):
    numbers = []
    number_idx = 0
    S = Counter(S)
    while(S):
        number = CHECK_ORDER[number_idx]
        counts = NUMBERS[number]
        while contains_number(S, counts):
            S -= counts
            numbers.append(number)
        number_idx += 1
        # print(S, numbers)
    result = ''.join(map(str, sorted(numbers)))
    print('Case #{}: {}'.format(T, result))


def main():
    n_cases = int(sys.stdin.readline().strip())
    for case in range(n_cases):
        S = sys.stdin.readline().strip()
        solve(case + 1, S)


if __name__ == '__main__':
    main()
