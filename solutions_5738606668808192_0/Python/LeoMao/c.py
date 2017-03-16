#! /usr/bin/env python3

import random
from math import sqrt, floor

N = 16
J = 50

M = 2**(N-2)

def get_factor(n):
    lim = floor(sqrt(n))
    for i in range(2, lim + 1):
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
                print(p, ' '.join(ret))
                ans.append((p, ret))
                cnt += 1
        except KeyboardInterrupt:
            print('interrupted')
            break

if __name__ == '__main__':
    main()
