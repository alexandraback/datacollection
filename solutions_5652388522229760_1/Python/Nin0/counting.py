#!/usr/bin/python3
import sys

def last_number(n):
    if n == 0:
        return 'INSOMNIA', -1
    x = n
    i = 0
    digits = set()
    for d in str(x):
        digits.add(d)
    while len(digits) < 10:
        x += n
        i += 1
        for d in str(x):
            digits.add(d)
    return x, i


if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in range(1, t+1):
        n = int(sys.stdin.readline())
        l, _ = last_number(n)
        print('Case #{0}: {1}'.format(i, l))
