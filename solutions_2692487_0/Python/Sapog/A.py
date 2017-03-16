#!/usr/bin/env python3
from collections import deque
import sys

p = sys.maxsize


def solve(data):
    res = p
    A, a = data
    n = len(a)
    if A == 1:
        return n
    a.sort()
    for rm in range(n + 1):
        s = A
        z = 0
        e = n - rm
        for i in range(e):
            while a[i] >= s:
                s = 2 * s - 1
                z += 1
            s += a[i]
        res = min(res, rm + z)
    return res


def read(fin):
    A, N = list(map(int, fin.readline().split()))
    a = list(map(int, fin.readline().split()))
    return A, a


def main():
    try:
        fin = open(sys.argv[1])
        if len(sys.argv) >= 3:
            fout = open(sys.argv[2], 'w')
        else:
            fout = sys.stdout
    except IndexError:
        print('Not enough command line options')
        sys.exit(1)
    except IOError as e:
        print(e)
        sys.exit(2)

    T = int(fin.readline())
    for t in range(T):
        data = read(fin)
        print('Case #{}: {}'.format(t + 1, solve(data)), file=fout)


if __name__ == '__main__':
    main()
