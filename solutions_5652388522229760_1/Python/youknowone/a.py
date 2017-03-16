#!/usr/bin/env python

import util
util.DEBUG = True
from util import *

finalset = frozenset('1234567890')


def a(base):
    if base == 0:
        return 'INSOMNIA'
    s = set()
    n = 0
    while s < finalset:
        n += base
        s = s.union(set(str(n)))
    return n

def solution(count):
    start = int_input()
    n = a(start)
    print_case(count, n)

if __name__ == '__main__':
    count = int_input()
    loop(count, solution)