#! /usr/bin/env python

from sys import stdin
import sys

def answer(stack, goal):
    if not stack:
        return -1
    newgoal = '-' if goal == '+' else '+'
    pos = stack.rfind(newgoal) + 1
    return 1 + answer(stack[:pos], newgoal)

ntest = input()

for test in xrange(ntest):
    S = stdin.readline().strip()
    print "Case #{}: {}".format(test + 1, answer(S, '+'))

