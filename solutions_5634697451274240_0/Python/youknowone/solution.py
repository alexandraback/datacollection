#!/usr/bin/env python

import util
# util.DEBUG = True
from util import *


class Stack(list):

    def __init__(self, s):
        super(Stack, self).__init__([c == '+' for c in s])

    def flip(self, i):
        self[:i] = [not c for c in self[:i][::-1]]

    def __str__(self):
        return ''.join(['+' if c else '-' for c in self])

    def pick_diff(self):
        prev = None
        for i, c in enumerate(self):
            if prev is None:
                prev = c
                continue
            if prev != c:
                return i
        return len(self)

    def flip_well(self):
        idx = self.pick_diff()
        self.flip(idx)

    def solve_regular(self):
        solution = [True] * len(self)
        n = 0
        while self != solution:
            n += 1
            self.flip_well()
            debug(self)
        return n


def solution(count):
    raw = raw_input()
    s = Stack(raw)
    answer = s.solve_regular()
    print_case(count, answer)


if __name__ == '__main__':
    count = int_input()
    loop(count, solution)