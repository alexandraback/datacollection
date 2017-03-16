#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def solve(s):
    s_len = len(s)
    result = [s[0]]
    for i in range(1, s_len):
        if result[0] <= s[i]:
            result.insert(0, s[i])
        else:
            result.append(s[i])
    return ''.join(result)


if __name__ == '__main__':
    test_cases = int(input())
    for t in range(1, test_cases + 1):
        s = list(input())
        print('Case #{}: {}'.format(t, solve(s)))
