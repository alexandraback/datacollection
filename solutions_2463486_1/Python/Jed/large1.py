#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: large1.py
# $Date: Sat Apr 13 23:20:12 2013 +0800
# $Author: jiakai <jia.kai66@gmail.com>

import math

RANGE = 10 ** 14

def get_nums():
    cur = 1
    rst = [1, 4, 9]
    class Done(Exception):
        pass

    def test(t):
        if t > RANGE:
            raise Done()
        if str(t) == str(t)[::-1]:
            rst.append(t)

    try:
        while True:
            curs = str(cur)
            cur_rev = curs[::-1]
            test(int(curs + cur_rev) ** 2)
            for i in range(10):
                test(int(curs + str(i) + cur_rev) ** 2)
            cur += 1

    except Done:
        rst.sort()
        return rst

def main():
    nr_case = int(raw_input())
    nums = get_nums()
    for casenu in range(1, nr_case + 1):
        A, B = map(int, raw_input().split())
        print 'Case #{}:'.format(casenu), \
                len(filter(lambda x: x >= A and x <= B, nums))


if __name__ == '__main__':
    main()
