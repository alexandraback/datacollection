#! /usr/bin/env python3

import sys
import random
from math import sqrt, floor

N = 32
J = 500

M = 2**(N-2)

def get_factor(n):
    LIM = 1000
    for i in range(2, LIM + 1):
        if n % i == 0:
            return i
    return None

def check(p):
    fs = []
    for x in range(2, 11):
        n = int(p, base=x)
        f = get_factor(n)
        if f is None:
            return None
        fs.append(f)
    return fs

def main():
    s = set()
    ans = []
    cnt = 0
    while cnt < J:
        try:
            r = random.randint(0, M)
            if r in s:
                continue
            s.add(r)
            p = '1' + bin(r)[2:].zfill(N - 2) + '1'
            ret = check(p)
            if ret:
                fs = ' '.join([str(x) for x in ret])
                print(p, fs)
                print(p, fs, file=sys.stderr)
                ans.append((p, ret))
                cnt += 1
        except KeyboardInterrupt:
            break

if __name__ == '__main__':
    main()
