#!/usr/bin/env python
import fileinput
import sys

#sys.setrecursionlimit(1005)


def solve(game):
    a, b, k = game
    count = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                count +=1
    return count


def make_answer(case, solution):
    return "Case #%i: %i" % (case, solution)


def get_input(lines):
    nextline = lambda: next(lines)
    cases = int(nextline())
    for _ in range(cases):
        a, b, k = map(int, nextline().split())
        yield a, b, k


def main():
    for i, game in enumerate(get_input(fileinput.input()), 1):
        print(make_answer(i, solve(game)))

if __name__ == '__main__':
    main()
