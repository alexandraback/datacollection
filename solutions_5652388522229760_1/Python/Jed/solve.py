#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 09 17:08:01 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve(n):
    if not n:
        return 'INSOMNIA'
    done = set()
    cur = 0
    while len(done) < 10:
        cur += n
        done.update(str(cur))
    return cur

def main():
    nr_case = int(input())
    for i in range(nr_case):
        print('Case #{}: {}'.format(i + 1, solve(int(input()))))

if __name__ == '__main__':
    main()
