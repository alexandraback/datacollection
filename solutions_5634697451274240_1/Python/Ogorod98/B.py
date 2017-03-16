#!/usr/bin/python3

def solve():
    inp = input() + '+'
    last = '?'
    groups = 0
    for c in inp:
        if c != last:
            groups += 1
        last = c
    return groups - 1

t = int(input())

for i in range(t):
    print("Case #{}: ".format(i + 1), solve())
