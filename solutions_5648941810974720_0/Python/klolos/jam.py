#!/usr/bin/env python

import sys


def print_result(result, i):
    sys.stdout.write("Case #%s: %s\n" % (i, result))


def readline():
    return sys.stdin.readline().rstrip('\n')


def splitline(f):
    return map(f, readline().split())


def subtract(letters, num, word):
    for _ in range(num):
        for l in word:
            letters.remove(l)


def reconstruct(nums):
    res = []
    for i in range(10):
        res += [i] * nums[i]

    return ''.join([str(n) for n in sorted(res)])


def solve():
    letters = splitline(list)[0]
    representatives = ["Z", "W", "X", "G", "H", "U", "F", "S", "O", "I"]
    words = ["ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR", "FIVE",
             "SEVEN", "ONE", "NINE"]
    ns = [0, 2, 6, 8, 3, 4, 5, 7, 1, 9]
    nums = [0] * 10
    for i in range(len(representatives)):
        num = letters.count(representatives[i])
        nums[ns[i]] = num
        subtract(letters, num, words[i])

    return reconstruct(nums)


def main():
    for i in range(int(readline())):
        print_result(solve(), i + 1)


if __name__ == '__main__':
    main()
