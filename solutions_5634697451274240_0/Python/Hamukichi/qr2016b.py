#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Modules from the Python standard library
import array
import itertools


def str2arr(input_str):
    return array.array("B", map(lambda x: x == "+", input_str))


def find_first_block(arr):
    elem = arr[0]
    it = itertools.takewhile(lambda x: bool(x) == elem, arr)
    block = array.array("B", it)
    return len(block)


def flip_first_block(arr):
    end = find_first_block(arr)
    for i in range(end):
        arr[i] = not arr[i]


def compute_minimum(input_str):
    arr = str2arr(input_str)
    answer = 0
    while not all(arr):
        flip_first_block(arr)
        answer += 1
    return answer


def main():
    t = int(input())
    for i in range(1, t + 1):
        print("Case #{}: {}".format(i, compute_minimum(input())))


if __name__ == '__main__':
    main()
