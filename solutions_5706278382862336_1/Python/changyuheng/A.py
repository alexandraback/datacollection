# -*- coding: utf-8 -*-


import sys


def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)

def solve():
    b, a = map(int, input().split('/'))
    gcf = gcd(a, b)
    b, a = b // gcf, a // gcf
    ans = 0

    if bin(a).count('1') != 1:
        return 'impossible'

    for i in range(1, 41):
        if 2 ** (-i) <= b / a:
            ans = i
            break

    return ans if ans > 0 else 'impossible'

def main():
    T = int(input())
    for i in range(1, T + 1):
        print('Case #{}: {}'.format(i, solve()))

if __name__ == '__main__':
    sys.exit(main())
