#!/usr/bin/env python
import sys
def read_int(): return int(sys.stdin.readline())
def read_floats(): return [float(x) for x in sys.stdin.readline().split()]

def calc(c, f, count):
    return c / (2.0 + (f * count))

def solve():
    # Read a problem
    C, F, X = read_floats()

    # Find the best
    best = calc(X, F, 0)
    count = 0
    total_firm = 0
    while True:
        total_firm += calc(C, F, count)
        total = total_firm + calc(X, F, count + 1)
        if best <= total:
            break
        best = total
        count += 1

    return best

if __name__ == '__main__':
    T = read_int()
    for i in range(T):
        print('Case #{}: {:.7f}'.format(i+1, solve()))
