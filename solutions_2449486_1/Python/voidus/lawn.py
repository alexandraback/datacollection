#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys
from itertools import product
#96989
#76777
#96989
#11111
#96989

def subrow_is_lower(row, cell):
    return all(item <= cell for item in row)

class Lawn(object):
    def __init__(self, n, m, lines):
        self.n = n
        self.m = m
        self.lines = lines

    def get_row(self, index):
        return self.lines[index]

    def get_col(self, index):
        return [row[index] for row in self.lines]
    
    def is_cell_reachable(self, i, j):
        row = self.get_row(i)
        col = self.get_col(j)
        cell = self.lines[i][j]
        r_before, r_after = row[:i], row[i:][::-1]
        c_before, c_after = col[:j], col[j:][::-1]
        row_sorted = subrow_is_lower(r_before, cell) and subrow_is_lower(r_after, cell)
        col_sorted = subrow_is_lower(c_before, cell) and subrow_is_lower(c_after, cell)
        return row_sorted or col_sorted

    def solve_debug(self):
        yes = True
        for i in range(self.n):
            for j in range(self.m):
                result = self.is_cell_reachable(i, j)
                if result is False:
                    yes = False
#                print(int(result), end='')
                if result == False:
                    yes = False
                    break
#            print()
            if yes is False:
                break
        return yes
    
    def solve(self):
        return all(self.is_cell_reachable(*item) for item in product(range(self.n), range(self.m)))

def solve_case(n, m, lines):
    return Lawn(n, m, lines).solve()

def handle_line(source):
    line = next(source)
    return tuple(map(int, line.strip().split(' ')))

def handle_input(source):
    number, = handle_line(source)
    for index in range(number):
        n, m = handle_line(source) 
        lines = []
        for i in range(n):
            lines.append(handle_line(source))
        result = solve_case(n, m, lines)
        print('Case #{0}: {1}'.format(index+1, 'YES' if result else 'NO'))
        if index % 100 == 0:
            sys.stdout.flush()

if __name__ == '__main__':
    handle_input(sys.stdin)
    #handle_input(open('input.txt', 'rt'))