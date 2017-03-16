#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: cvt.py
# $Date: Sat Apr 09 19:05:01 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>
#
# convert the result produced by search.cpp to codejam submission

import sys
import subprocess

small_primes = [2]


def find_factor(n):
    for i in small_primes:
        if n % i == 0:
            return i
    subp = subprocess.Popen(['factor', str(n)], stdout=subprocess.PIPE)
    fac, _ = subp.communicate()
    return fac.split()[1].decode('utf-8')

def main():
    for i in range(2, 1000):
        for k in small_primes:
            if i % k == 0:
                break
            if k * k >= i:
                small_primes.append(i)
                break
    #print(small_primes)

    print('Case #1:')
    for seq in sys.stdin:
        seq = seq.strip()
        line = [seq]
        line.extend(find_factor(int(seq, i)) for i in range(2, 11))
        print(' '.join(map(str, line)))

if __name__ == '__main__':
    main()
