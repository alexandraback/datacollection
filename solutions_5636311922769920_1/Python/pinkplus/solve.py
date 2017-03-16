#!/usr/bin/env python3

def largeBaseInt(digits, base):
    n = 0
    x = 1
    for digit in reversed(digits):
        n += x * digit
        x *= base
    return n

def solve(K, C, S):
    if S < K / C:
        return

    l = list(range(K))
    if K % C != 0:
        l = [0] * (C - K % C) + l

    retval = []
    for i in range(len(l) // C):
        retval.append(largeBaseInt(l[C*i:C*(i+1)], K) + 1)

    return retval

def main():
    T = int(input())
    for i in range(1, T+1):
        K, C, S = [int(x) for x in input().split()]
        retval = solve(K, C, S)
        print('Case #{}: '.format(i), end='')
        if retval is None:
            print('IMPOSSIBLE')
        else:
            print(*retval)

if __name__ == '__main__':
    main()
