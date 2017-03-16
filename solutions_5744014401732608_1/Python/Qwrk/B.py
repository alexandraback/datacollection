import numpy as np


def solve(b, m):
    if m == 2**(b-2):
        r = '0' + '1' * (b - 1)
    else:
        r = bin(m)[2:].zfill(b - 1) + '0'
    print(r)
    for i in range(2, b + 1):
        print('0' * i + '1' * (b - i))


def main():
    t = int(input())
    for case in range(1, t + 1):
        b, m = list(map(int, input().split()))
        if m > 2**(b-2):
            print('Case #%d: IMPOSSIBLE' % case)
        else:
            print('Case #%d: POSSIBLE' % case)
            solve(b, m)

if __name__ == '__main__':
    main()