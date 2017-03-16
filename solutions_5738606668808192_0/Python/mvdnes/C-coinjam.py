#!/usr/bin/env python3

import sys

def get_factor(n):
    if n <= 3:
        return None
    elif n % 2 == 0:
        return 2
    elif n % 3 == 0:
        return 3
    i = 5
    while i*i <= n and i < 1000:
        if n % i == 0:
            return i
        elif n % (i + 2) == 0:
            return i + 2
        i += 6
    return None

def main():
    t = int(sys.stdin.readline().strip())
    for i in range(1, t+1):
        print("Case #{}:".format(i))
        doit()

def convert_base(inp, b):
    if b == 2:
        return inp
    else:
        return int(bin(inp)[2:], b)

def doit():
    N, J = [int(v) for v in sys.stdin.readline().strip().split(' ')]
    val = (1 << (N-1)) | 1
    j = 0
    while j < J:
        factors = []
        for b in range(2, 11):
            valb = convert_base(val, b)
            factor = get_factor(valb)
            if factor is None:
                break
            else:
                factors.append(factor)
        if len(factors) == 9:
            j += 1
            print("{:b} {}".format(val, ' '.join([str(v) for v in factors])))
        val += 2

if __name__ == "__main__":
    main()
