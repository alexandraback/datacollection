#!/usr/bin/env python3

from functools import partial

def cuml_area(start, x):
    return (2*start-1)*x + 2*x*x

def bsearch(f, value, low, high):
    while low <= high:
        mid = (low + high) // 2
        if value < f(mid):
            high = mid - 1
        elif f(mid) < value:
            low = mid + 1
        else:
            return mid
    return high

def main():
    n = int(input())
    for i in range(n):
        start, paint = map(int, input().split())
        rings = bsearch(partial(cuml_area, start), paint, 0, 10**18)
        print('Case #{}: {}'.format(i+1, rings))

if __name__ == '__main__':
    main()
