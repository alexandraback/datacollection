#!/usr/bin/python3

from codejam import CodeJam

def pancakes(f):
    stack = [True if p == '+' else False for p in f.readline().strip()]
    flips = int(not stack[-1])
    ptr = 0
    parity = stack[0]
    while ptr < len(stack):
        try:
            ptr += stack[ptr:].index(not parity)
        except:
            return flips
        flips += 1
        parity = not parity



cj = CodeJam(2016, 'qual', 'B', pancakes)
