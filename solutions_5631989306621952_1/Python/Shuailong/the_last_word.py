#!/usr/bin/env python
# encoding: utf-8

"""
the_last_word.py
 
Created by Shuailong on 2016-04-16.

https://code.google.com/codejam/contest/4304486/dashboard

"""


def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        S = raw_input()
        res = S[0]
        for i in range(1, len(S)):
            candidate1 = res + S[i]
            candidate2 = S[i] + res
            if candidate1 > candidate2:
                res = candidate1
            else:
                res = candidate2

        print 'Case #{}: {}'.format(t, res)


if __name__ == '__main__':
    main()