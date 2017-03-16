import sys
from collections import defaultdict
# sys.stdin = open('b1.in')
# sys.stdin = open('B-small-attempt0.in')
sys.stdin = open('B-large.in')
sys.stdout = open('out.txt', 'w')


def solve_it(b, m):
    if m > 2 ** (b - 2):
        return False, None
    if b == 2:
        return True, [[0, 1], [0, 0]]
    a = [[0] * b for _ in range(b)]
    k = 0
    p = 1
    while 2 * p < m:
        k += 1
        p *= 2
    for u in range(k + 1):
        i = b - 1 - u - 1
        for j in range(i + 1, b):
            a[i][j] = 1

    if m == 2 * p:
        a[b - k - 3][b - 1] = 1
        m -= 1
    for i in range(k + 1):
        if m & (1 << i):
            a[b - k - 3][b - 2 - i] = 1

    for i in range(b - k - 3):
        a[i][i + 1] = 1
    return True, a


def main():

    n_cases = int(input())
    for test_case in range(1, n_cases + 1):
        B, M = map(int, input().split())
        print(test_case, file=sys.stderr, end=' ')
        possible, a = solve_it(B, M)
        res = 'IMPOSSIBLE'
        if possible:
            lines = [''.join(map(str, row)) for row in a]
            res = '\n'.join(['POSSIBLE'] + lines)
        print('Case #' + str(test_case) + ':', res)

    print(file=sys.stderr)

if __name__ == '__main__':
    main()
