#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys
import math

def is_palindrome(number):
    strnum = str(number)
    middle, mod = divmod(len(strnum), 2)
    return strnum[:middle] == strnum[middle+mod:][::-1]

def solve(a, b):
    low = math.ceil(math.sqrt(a))
    high = math.floor(math.sqrt(b))
    counter = 0
    for number in range(low, high+1):
        if is_palindrome(number) and is_palindrome(number**2):
            counter += 1
    return counter

def handle_input(source):
    number = int(next(source).strip())
    for index in range(number):
        line = next(source).strip()
        a, b = map(int, line.split(' '))
        result = solve(a, b)
        print('Case #{0}: {1}'.format(index+1, result))

if __name__ == '__main__':
    handle_input(sys.stdin)
