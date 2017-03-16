from itertools import *
import brute


def memo(fn):
    m = {}
    def inner(*args):
        key = tuple(args)
        if not key in m:
            m[key] = fn(*args)
        return m[key]
    return inner


@memo
def opts(num_cols):
    """
    All options for num_cols width.
    """
    res = []
    for num_bombs in range(num_cols+1):
        for num_n in range(num_cols+1):
            if num_bombs + num_n > num_cols:
                continue
            num_0 = num_cols - num_bombs - num_n
            assert num_0 >= 0
            x = num_bombs*'*' + num_n*'N' + num_0*'0'
            if '*0' in x:
                continue
            res.append(x)
    return res


def is_compatible(A, B):
    assert len(A) == len(B)

    i = 0
    for pa, a, na, pb, b, nb in izip('X' + A, A, A[1:] + 'X',
                                     'X' + B, B, B[1:] + 'X'):
        a_neighbors = [pa, na, pb, b, nb]
        b_neighbors = [pa, na, pb, a, nb]
        if a == '0' and '*' in a_neighbors:
            return False
        if a == 'N' and not '*' in a_neighbors:
            return False
        if a == '*' and '0' in a_neighbors:
            return False
        if b == 'N' and not '0' in b_neighbors:
            return False
        #print
        i += 1

    return True


@memo
def compatibles(xs):
    n = len(xs)
    res = []
    for ys in opts(n):
        if is_compatible(xs, ys):
            res.append(ys)
    return res


@memo
def count_bombs(xs):
    return sum(1 for c in xs if c == '*')


@memo
def dig(prev, row, row_max, bombs_rem):
    #print row*' ',
    #print 'dig(%s, %d, %d, %d)' % (prev, row, row_max, bombs_rem,)


    if row == row_max:
        #if bombs_rem == 0:
        #    print row*' ' + ' GOOD!'
        return '' if bombs_rem == 0 else None

    n = len(prev)
    if (row_max - row)*n < bombs_rem:
        return None

    for ys in compatibles(prev):
        nbrem = bombs_rem - count_bombs(ys)
        if nbrem < 0:
            continue
        rem = dig(ys, row+1, row_max, nbrem)
        if not rem is None:
            return ys + '\n' + rem


def solve(rows, cols, bombs):
    for xs in opts(cols):
        if 'NN' in xs:
            continue
        if not '0' in xs and not 'N' in xs:
            continue

        nbrem = bombs - count_bombs(xs)
        if nbrem < 0:
            continue
        res = dig(xs, 1, rows, nbrem)
        if not res is None:
            vs = xs + '\n' + res
            while vs[-1] == '\n':
                vs = vs[:-1]
            return vs

"""
import random
import time
print solve(2, 2, 3)
while True:
    R = random.randint(1, 5)
    C = random.randint(1, 4)
    M = random.randint(0, R*C-1)
    print R, C, M
    m = solve(R, C, M)
    if m:
        assert sum(1 for c in m if c == '*') == M
        assert brute.solve_one(R, C, M)

        grid = [[0 for c in range(C)] for r in range(R)]

        for i, row in enumerate(m.split('\n')):
            for j, col in enumerate(row):
                if col == '*':
                    for rr, cc in brute.neighbors(R, C, i, j):
                        if grid[rr][cc] != '*':
                            grid[rr][cc] = 1
        assert brute.search(R, C, grid, 0, C-1) == R*C-M


        print m
    else:
        print 'nocando'
        assert not brute.solve_one(R, C, M)
    #time.sleep(1)
"""

import sys
import time
_input = sys.stdin.read().split()[::-1]
I = lambda: int(_input.pop())
D = lambda: float(_input.pop())


tpre = time.time()
sys.setrecursionlimit(10000)

for t in range(1, I()+1):
    R, C, M = I(), I(), I()

    print 'Case #%d:' % t
    m = solve(R, C, M)
    if m:
        if R*C <= 30:
            assert brute.solve_one(R, C, M)

        grid = [[0 for c in range(C)] for r in range(R)]
        for i, row in enumerate(m.split('\n')):
            for j, col in enumerate(row):
                if col == '*':
                    for rr, cc in brute.neighbors(R, C, i, j):
                        if grid[rr][cc] != '*':
                            grid[rr][cc] = 1
        assert brute.search(R, C, grid, 0, C-1) == R*C-M

        if not '0' in m:
            assert sum(1 for c in m if c == 'N') == 1
            m = m.replace('N', 'c')
        else:
            z0 = m.index('0')
            m2 = m[:z0] + 'c' + m[z0+1:]
            assert len(m) == len(m2)
            m = m2

        m = m.replace('0', '.').replace('N', '.')
        print m
    else:
        print 'Impossible'
        if R*C <= 30:
            assert not brute.solve_one(R, C, M)
