#!/usr/bin/python

import sys

def solve(inp):
    numbers = []

    for i in range(inp.count('Z')):
        numbers.append(0)
        for l in 'ZERO':
            inp.remove(l)
    for i in range(inp.count('W')):
        numbers.append(2)
        for l in 'TWO':
            inp.remove(l)
    for i in range(inp.count('U')):
        numbers.append(4)
        for l in 'FOUR':
            inp.remove(l)

    for i in range(inp.count('X')):
        numbers.append(6)
        for l in 'SIX':
            inp.remove(l)

    for i in range(inp.count('G')):
        numbers.append(8)
        for l in 'EIGHT':
            inp.remove(l)

    for i in range(inp.count('F')):
        numbers.append(5)
        for l in 'FIVE':
            inp.remove(l)
    for i in range(inp.count('V')):
        numbers.append(7)
        for l in 'SEVEN':
            inp.remove(l)
    for i in range(inp.count('I')):
        numbers.append(9)
        for l in 'NINE':
            inp.remove(l)
    for i in range(inp.count('H')):
        numbers.append(3)
        for l in 'THREE':
            inp.remove(l)


    for i in range(inp.count('O')):
        numbers.append(1)
        for l in 'ONE':
            inp.remove(l)
    numbers.sort()
    return numbers

with open(sys.argv[1], 'r') as f:
    cases = int(f.readline())
    for case in range(cases):
        inp = list(f.readline().strip())
        ans = solve(inp)
        ans = ''.join(map(str, ans))
        print("Case #{:}: {:}".format(case+1, ans))


