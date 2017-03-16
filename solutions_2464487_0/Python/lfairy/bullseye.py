#!/usr/bin/env python3

from functools import partial
from itertools import count

def radii(start):
    return count(start, step=2)

def areas(start):
    for r in radii(start):
        yield 2*r + 1

def main():
    n = int(input())
    for i in range(n):
        start, paint = map(int, input().split())
        next_area = partial(next, areas(start))
        rings = 0
        while True:
            delta = next_area()
            if paint < delta:
                break
            else:
                paint -= delta
                rings += 1
        print('Case #{}: {}'.format(i+1, rings))

if __name__ == '__main__':
    main()
