#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys

class Line(object):
    def __init__(self, line):
        self.line = line

    def get_winner(self):
        x_won = all(char in ('X', 'T') for char in self.line)
        o_won = all(char in ('O', 'T') for char in self.line)
        result = [None, 'X', 'O'][o_won*2 + x_won]
        return result
    

class Board(object):
    def __init__(self, lines):
        self.lines = lines

    def solve(self):
        rows = [Line(self.get_row(index)) for index in range(4)]
        cols = [Line(self.get_column(index)) for index in range(4)]
        diags = [Line(self.get_diag(index)) for index in range(2)]
        lines = rows + cols + diags
        results = [line.get_winner() for line in lines]
        significant = [result for result in results if result is not None]
        if len(significant) >= 1:
            winner = significant[0]
            return '%s won' % winner
        elif self.is_not_completed_yet():
            return 'Game has not completed'
        else:
            return 'Draw'

    def get_row(self, index):
        return self.lines[index]

    def get_column(self, index):
        return ''.join(row[index] for row in self.lines)

    def get_diag(self, index):
        iterator = iter(range(4) if index==0 else range(4)[::-1])
        return ''.join(row[next(iterator)] for row in self.lines)

    def is_not_completed_yet(self):
        flattened = ''.join(self.lines)
        return any(char=='.' for char in flattened)


if __name__ == '__main__':
    inputdata = sys.stdin
    number = next(inputdata).rstrip()
    number = int(number)
    for case in range(number):
        lines = []
        for j in range(4):
            lines.append(next(inputdata).rstrip())
        if case != number-1:
            assert next(inputdata), '\n'
        board = Board(lines)
        result = board.solve()
        print('Case #{0}: {1}'.format(case+1, result))
