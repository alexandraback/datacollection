#!/usr/bin/python3

import sys

def pow2():
    x = 1
    while True:
        yield x
        x <<= 1

def solve(a, b):
    if 2**40 % b != 0:
        return None
    else:
        nb = 2**40
        na = a * (nb // b)
        for l, x in enumerate(pow2()):
            if x > na:
                break
        return 40 - l + 1

def nod(a, b):
    while a!=0 and b!=0:
        if a > b:
            a = a % b
        else:
            b = b % a
    return a + b

def main():
    T = int(next(sys.stdin))
    for i, line in enumerate(sys.stdin, 1):
        a, b = (int(x) for x in line.strip().split('/'))
        a, b = a // nod(a, b), b // nod(a, b)
        print("Case #{}: {}".format(i, solve(a, b) or 'impossible'))

if __name__ == '__main__':
    main()

