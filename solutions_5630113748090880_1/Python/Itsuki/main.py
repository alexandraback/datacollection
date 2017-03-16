#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def solve(n, input_data):
    counter = {}
    for i in range(2 * n - 1):
        for size in input_data[i]:
            counter[size] = counter.get(size, 0) + 1
    result = []
    for key, value in counter.items():
        if value % 2 != 0:
            result.append(key)
    result = sorted(result)
    result_str = ''
    for i in range(len(result) - 1):
        result_str += str(result[i])
        result_str += ' '
    result_str += str(result[-1])
    return result_str


if __name__ == '__main__':
    test_cases = int(input())
    for t in range(1, test_cases + 1):
        n = int(input())
        input_data = []
        for i in range(2 * n - 1):
            input_data.append([int(s) for s in input().split(' ')])
        print('Case #{}: {}'.format(t, solve(n, input_data)))
