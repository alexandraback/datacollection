#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def ReadIn():
    cases = int(raw_input())
    for case in xrange(1, cases + 1):
        n, m = [int(x) for x in raw_input().split()]
        lawn = [[int(x) for x in raw_input().split()] for i in xrange(n)]
        yield case, lawn

def Solve(lawn):
    tlawn = zip(*lawn)
    for r in xrange(len(lawn)):
        for c in xrange(len(lawn[0])):
            if all(x <= lawn[r][c] for x in lawn[r]) or all(x <= lawn[r][c] for x in tlawn[c]): continue
            else: return 'NO'
    return 'YES'

if __name__ == '__main__':
    for case, lawn in ReadIn():
        print 'Case #%d: %s' % (case, Solve(lawn))
