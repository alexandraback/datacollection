#!/usr/bin/python3

import sys

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)


switch = {'+': '-', '-': '+'}

def flip(pancakes, target):
    if all(p == target for p in pancakes):
        return 0
    else:
        idx = pancakes.rstrip(target).rfind(target) + 1
        return 1 + flip(pancakes[:idx], switch[target])

if __name__ == '__main__':
    
    T = int(input())
    for case in range(1, T+1):
        S = input()
        result = flip(S, '+')

        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
