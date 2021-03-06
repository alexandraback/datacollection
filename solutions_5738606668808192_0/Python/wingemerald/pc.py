#!/usr/bin/env python3
import sys

def is_prime(x):
    now = 2
    while True:
        if now ** 2 > x:
            break
        if x % now == 0:
            return (False, now)
        now += 1
    return (True, 0)

def is_answer(x):
    for i in range(2, 11):
        if is_prime(int(x, i))[0]:
            return False
    return True

def print_answer(x):
    print(x, end=" ")
    for i in range(2, 11):
        print(is_prime(int(x, i))[1], end=" ")
    print()

def get_str(n, x):
    return '1' + str(bin(x))[2:].zfill(n-2) + '1'

def get_input():
    case = int(input())
    tmp = input().split()
    return case, int(tmp[0]), int(tmp[1])

if __name__ == "__main__":
    case, n, j = get_input()
    now = 0
    print("Case #1:")
    while j:
        s = get_str(n, now)
        if is_answer(s):
            print_answer(s)
            j -= 1
        now += 1
