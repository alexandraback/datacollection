#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve1(r, c, m, e):
    return ['c' + ((e-1)*'.') + (c-e)*'*']

def solve2(r, c, m, e):
    if e == 1:
        return ['c' + (c-1)*'*', c*'*']
    if e == 2 or e % 2 == 1:
        return None
    e_cols = e / 2
    return [
        'c' + (e_cols-1)*'.' + (c-e_cols)*'*',
        e_cols*'.' + (c-e_cols)*'*'
    ]

def solveN(*args):
    x = solveNx(*args)
    if x:
        res = []
        for row in x:
            res.append(''.join(row))
        return res
    return None

def dbg(x):
    res = []
    for row in x:
        res.append(''.join(row))
    return '\n'.join(res)

def solveNx(r, c, m, e):
    if e == 2 or e == 3 or e == 5 or e == 7:
        return None
    x = [['*']*c for i in range(r)]
    x[0][0] = 'c'
    if e == 1:
        return x
    x[1][0] = '.'
    x[0][1] = '.'
    x[1][1] = '.'
    e -= 4;
    ri = 2
    ci = 2
    #print dbg(x), r, c, e
    while e > 1 and (ri < r or ci < c):
        if ri < r:
            x[ri][0] = '.'
            x[ri][1] = '.'
            ri += 1
            e -= 2
        if e > 1 and ci < c:
            x[0][ci] = '.'
            x[1][ci] = '.'
            ci += 1
            e -= 2

    ri = 2
    ci = 2
    while e > 0:
        x[ri][ci] = '.'
        ci += 1
        if ci == c:
            ri += 1
            ci = 2
        e -= 1
    return x

def solve(r, c, m):
    swap = False
    if r > c:
        r, c = c, r
        swap = True
    e = r*c-m
    if r == 1:
        result = solve1(r, c, m, e);
    elif r == 2:
        result = solve2(r, c, m, e);
    else:
        result = solveN(r, c, m, e);

    if not result:
        return 'Impossible'
    if swap:
        #result = zip(*result[::-1])
        result = map(lambda row : ''.join(row), zip(*result[::-1]))
    return '\n'.join(result)

if __name__ == "__main__":
    testcases = input()
    for case_n in xrange(1, testcases+1):
        case_data = map(int, raw_input().split())
        print("Case #%i:\n%s" % (case_n, solve(*case_data)))
