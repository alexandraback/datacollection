#!/usr/bin/python3

import sys

def can_do(n, p):
    # O(d * P), P = max_i p_i
    for r in range(n):  # r is the number of special minutes.
        m = n - r  # Maximal allowed content on a plate.
        special_left = r
        for i in range(len(p)):
            if p[i] <= m:
                break
            special_moves = (p[i] // m) - 1
            if p[i] % m != 0:
                special_moves += 1
            special_left -= special_moves
            if special_left < 0:
                break
        if special_left >= 0:
            return True
    return False

def solve(p):
    # Using bisection
    # O(d * P * lg P), P = max_i p_i
    p.sort(key=lambda x: -x)
    a, b = 0, max(p)
    while a < b:
        c = (a + b) // 2
        if can_do(c, p):
            b = c
        else:
            a = c + 1    
    return a

t = int(sys.stdin.readline())  # T <= 100
for i in range(1, t+1):
    d = int(sys.stdin.readline())
    # d <= 1000, p_i <= 1000
    p = [int(x) for x in sys.stdin.readline().split()]
    min_time = solve(p)
    print('Case #{0}: {1}'.format(i, min_time))
