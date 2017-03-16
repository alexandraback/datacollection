#!/usr/local/bin/pythonw3.2
from itertools import *
def printM(M):
    t = M[0][0]
    M[0][0] = 'c'
    print('\n'.join(''.join(str(a) for a in row) for row in M))
    M[0][0] = t

def aroundGen(i, j, M, l = lambda x, y: True):
    for ii in range(max(i - 1, 0), min(len(M), i + 2)):
        for jj in range(max(j - 1, 0), min(len(M[ii]), j + 2)):
            if l(ii, jj):
                yield ii, jj

def check(M):
    visited = set([(0, 0)])
    stack = [(0, 0)]
    while stack:
        i, j = stack.pop()
        if sum(M[a_i][a_j] == '*' for a_i, a_j in aroundGen(i, j, M)) != 0:
            continue
        for a_i, a_j in aroundGen(i, j, M, lambda a_i, a_j: (a_i, a_j) not in visited):
            visited.add((a_i, a_j))
            stack.append((a_i, a_j))
    return len(visited) == sum(sum(el == '.' for el in row) for row in M)

def solve(height, width, bombs):
    space = width * height - bombs
    for w, h in product(range(1, width + 1), range(1, height + 1)):
        for tw, th  in product(range(w), range(h)):
            if w * h - (tw + th - (tw != 0 and th != 0)) != space:
                continue

            M = [['*' for _ in range(width)] for _ in range(height)]
            for i, j in product(range(h), range(w)):
                M[i][j] = '.'

            for i in range(tw):
                M[h - 1][w - i - 1] = '*'
            for i in range(th):
                M[h - i - 1][w - 1] = '*'
            if check(M):
                return M
    return False

for case in range(1, int(input()) + 1):
    M = solve(*[int(x) for x in input().strip().split()])
    print('Case #{}:'.format(case))
    print('Impossible') if not M else printM(M)
