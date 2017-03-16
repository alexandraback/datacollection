import sys
from collections import defaultdict
sys.stdin = open('A-large.in')
sys.stdout = open('out-large.txt', 'w')


def check(s):
    a = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
         "SIX", "SEVEN", "EIGHT", "NINE"]
    for l in s:
        for i in range(10):
            if l in a[i]:
                print(i, end="")
        print()


def solve_it(s):
    h = defaultdict(int)
    for l in s:
        h[l] += 1
    r = defaultdict(int)
    r[0] = h['Z']
    r[6] = h['X']
    r[8] = h['G']
    r[2] = h['W']
    r[7] = h['S'] - r[6]
    r[3] = h['H'] - r[8]
    r[5] = h['V'] - r[7]
    r[4] = h['F'] - r[5]
    r[1] = h['O'] - r[0] - r[2] - r[4]
    r[9] = h['I'] - r[5] - r[6] - r[8]
    res = ''.join([str(i) * r[i] for i in range(10)])
    return res


def main():

    # check('ZXGWSHVFOI')

    n_cases = int(input())
    for test_case in range(1, n_cases + 1):
        s = input()
        print(test_case, file=sys.stderr, end=' ')
        res = solve_it(s)
        print('Case #' + str(test_case) + ':', res)

    print(file=sys.stderr)

if __name__ == '__main__':
    main()
