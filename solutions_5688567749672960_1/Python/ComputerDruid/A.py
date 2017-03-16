#!/usr/bin/env python3

def digits(num):
    num -= 1
    if num == 0:
        return 1
    step_result = 0
    side_digits = num // 2
    side_step_cost = 10 ** side_digits - 1
    flip_cost = 1
    if num == 1:
        flip_cost = 0
    center_cost = 0
    if num % 2 == 1:
        center_cost = 10 ** side_digits * 9
    return digits(num) + side_step_cost + center_cost + flip_cost + side_step_cost

def solve_noflip(N):
    N = str(N)
    size = len(N)
    base = digits(size)
    cost = int(str(int(N[0]) - 1) + N[1:])
    return base + cost

def solve_regular(N):
    N = str(N)
    size = len(N)
    if size == 1:
        return int(N)
    base = digits(size)
    left_size = size // 2
    right_size = size - left_size
    left = N[:left_size]
    right = N[left_size:]
    left_cost = int(left[::-1])
    flip_cost = 1
    if left_cost == 1:
        #no need to flip
        return int(right) + base
    right_cost = int(right) - 1 #after flip, right part has 1 already
    if right_cost < 0:
        #we're in trouble, can't flip for free
        left = str(int(left) - 1)
        #recompute_left_cost
        left_cost = int(left[::-1])
        flip_cost += 10 ** right_size - 1
        right_cost = 0
    return left_cost + flip_cost + right_cost + base

def solve(N):
    return min(solve_regular(N), solve_noflip(N))

T = int(input())
for t in range(T):
    N = int(input())
    print("Case #" + str(t+1) +":", solve(N))
