__author__ = 'karol'

import sys
import itertools
import bisect

MAX_VALUE = 10 ** 14


def is_palindrome(value):
    return str(value) == str(value)[::-1]


def odd_palindrome_fn(i):
    return int(str(i) + str(i)[-2::-1])


def even_palindrome_fn(i):
    return int(str(i) + str(i)[::-1])


def generate(palindrome_fn):
    for i in itertools.count(1):
        palindrome = palindrome_fn(i)
        square = palindrome ** 2
        if square > MAX_VALUE:
            break
        if is_palindrome(square):
            yield square


def main():
    nums = sorted(itertools.chain(generate(odd_palindrome_fn), generate(even_palindrome_fn)))
    T = int(sys.stdin.readline())
    for case in xrange(1, T + 1):
        N, M = (int(val) for val in sys.stdin.readline().split())
        first = bisect.bisect_left(nums, N)
        last = bisect.bisect_right(nums, M)
        solution = last - first
        print "Case #%d: %s" % (case, solution)

main()