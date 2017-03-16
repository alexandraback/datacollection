#!/usr/bin/env python
# encoding: utf-8

"""
rank_and_file.py.py
 
Created by Shuailong on 2016-04-16.

https://code.google.com/codejam/contest/4304486/dashboard#s=p1

"""

from collections import Counter
def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        N = int(raw_input())
        ls = []
        for _ in xrange(2*N-1):
            l = [int(i) for i in raw_input().split(' ')]
            ls.append(l)
        nums = []
        for l in ls:
            nums += l
        c = Counter(nums)
        res = []
        for i in c:
            if c[i] % 2 == 1:
                res.append(i)
        res.sort()
        res = [str(i) for i in res]
        res = ' '.join(res)
        print 'Case #{}: {}'.format(t, res)


if __name__ == '__main__':
    main()
