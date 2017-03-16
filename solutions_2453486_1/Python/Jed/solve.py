#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 13 21:49:49 2013 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve_case(state):
    class Result(Exception):
        msg = None
        def __init__(self, msg):
            self.msg = msg

    def check(s):
        if set(s).issubset(set('XT')):
            raise Result('X won')
        if set(s).issubset(set('OT')):
            raise Result('O won')

    try:
        for i in range(4):
            check(state[i])
            check([s[i] for s in state])
        check(''.join(state[i][i] for i in range(4)))
        check(''.join(state[i][3 - i] for i in range(4)))
    except Result as rst:
        return rst.msg

    for i in state:
        if '.' in i:
            return 'Game has not completed'
    return 'Draw'

def main():
    ncase = int(raw_input())
    for casenu in range(1, ncase + 1):
        print 'Case #{}:'.format(casenu), \
                solve_case([raw_input() for i in range(4)])
        raw_input()


if __name__ == '__main__':
    main()
