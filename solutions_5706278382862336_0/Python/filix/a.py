#!/usr/bin/python3 -t

from fractions import gcd


def read_ints():
    return map(int, input().split())


def is_power2(x):
    return x > 0 and (x & (x - 1)) == 0


def solve():
    p, q = map(int, input().split('/'))
    d = gcd(p, q)
    p //= d
    q //= d
    # print(p, q)
    if not is_power2(q) or q > (2 ** 40):
        print('impossible')
        return
    result = 0
    while p < q:
        p *= 2
        result += 1
    print(result)

if __name__ == '__main__':
    for test_case in range(int(input())):
        print('Case #{}: '.format(test_case + 1), end='')
        solve()