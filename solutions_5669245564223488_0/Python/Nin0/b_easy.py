#!/usr/bin/python3

import sys

modulo = 1000000007
t = int(sys.stdin.readline())

def short(x):
    s = '#'
    for c in ''.join(x):
        if c != s[-1]:
            s += c
    return s[1:]

def is_valid(x):
    x = ''.join([l for l in x if l != '@'])
    x = short(x)
    return len(x) == len(set(x))

def solve(trains):
    trains = [short(x) for x in trains]
    # print(trains)
    if not is_valid(trains[0]):
        return 0
    sol = {trains[0]: 1}
    
    for x in trains[1:]:
        new_sol = dict()
        for k, v in sol.items():
            for i in range(len(k)):
                if k[i] != '@': continue
                nova = k[:i] + '@' + x + '@' + k[i+1:]
                if is_valid(nova):
                    new_sol[nova] = new_sol.get(nova, 0) + v
            nova = k + '@' + x
            if is_valid(nova):
                new_sol[nova] = new_sol.get(nova, 0) + v
            nova = x + '@' + k
            if is_valid(nova):
                new_sol[nova] = new_sol.get(nova, 0) + v
        sol = new_sol
        # print(sol)
                    
    return sum(sol.values())

for test_case_number in range(1, t+1):
    n = map(int, sys.stdin.readline())
    trains = sys.stdin.readline().split()
    print('Case #%d: %d' % (test_case_number, solve(trains) % modulo))
