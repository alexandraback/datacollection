#!/usr/bin/env python
# -*- coding: utf-8 -*-

import bisect
import sys

def generate_choises(n, m):
    if m == 0:
        yield []

    elif m == 1:
        for i in xrange(n):
            yield [i]

    elif 1 < m:
        for i in xrange(m-1, n):
            for r in generate_choises(i, m-1):
                yield r + [i]

def generate_ones_distribution(number_of_digits, number_of_ones):
    for choose in generate_choises(number_of_digits, number_of_ones):
        result = [0]*number_of_digits
        for i in choose:
            result[i] = 1
        yield result


def generate_1_padding_padding_1(padding_size):
    number_of_ones = 0
    while 2*(number_of_ones + 1) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [1] + padding + padding[::-1] + [1]
        number_of_ones += 1

def generate_1_padding_0_padding_1(padding_size):
    number_of_ones = 0
    while 2*(number_of_ones + 1) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [1] + padding + [0] + padding[::-1] + [1]
        number_of_ones += 1

def generate_1_padding_1_padding_1(padding_size):
    number_of_ones = 0
    while 1 + 2*(number_of_ones + 1) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [1] + padding + [1] + padding[::-1] + [1]
        number_of_ones += 1

def generate_1_padding_2_padding_1(padding_size):
    number_of_ones = 0
    while 4 + 2*(number_of_ones + 1) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [1] + padding + [2] + padding[::-1] + [1]
        number_of_ones += 1

def generate_2_padding_padding_2(padding_size):
    number_of_ones = 0
    while 2*(number_of_ones + 4) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [2] + padding + padding[::-1] + [2]
        number_of_ones += 1

def generate_2_padding_0_padding_2(padding_size):
    number_of_ones = 0
    while 2*(number_of_ones + 4) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [2] + padding + [0] + padding[::-1] + [2]
        number_of_ones += 1

def generate_2_padding_1_padding_2(padding_size):
    number_of_ones = 0
    while 1 + 2*(number_of_ones + 4) <= 9 and number_of_ones <= padding_size:
        for padding in generate_ones_distribution(padding_size, number_of_ones):
            yield [2] + padding + [1] + padding[::-1] + [2]
        number_of_ones += 1


def integize(decomposition):
    result = 0
    for digit in decomposition:
        result = 10*result + digit
    return result


def generate_roots():
    yield 0
    yield 1
    yield 2
    yield 3
    for padding_size in xrange(26):
        for root in generate_1_padding_padding_1(padding_size):
            yield integize(root)
        for root in generate_2_padding_padding_2(padding_size):
            yield integize(root)

        for root in generate_1_padding_0_padding_1(padding_size):
            yield integize(root)
        for root in generate_1_padding_1_padding_1(padding_size):
            yield integize(root)
        for root in generate_1_padding_2_padding_1(padding_size):
            yield integize(root)

        for root in generate_2_padding_0_padding_2(padding_size):
            yield integize(root)
        for root in generate_2_padding_1_padding_2(padding_size):
            yield integize(root)


FAIR_SQUARED_NUMBERS = sorted([ x*x for x in generate_roots()])

def NumberOfFairSquardNumbers(first, last):
    return bisect.bisect_right(FAIR_SQUARED_NUMBERS, last) - bisect.bisect_left(FAIR_SQUARED_NUMBERS, first)


def Integers(stream):
    for line in stream:
        for token in line.split():
            yield int(token)

integers = Integers(sys.stdin)

number_of_cases = integers.next()
for case_no in xrange(1, number_of_cases + 1):
    first = integers.next()
    last = integers.next()
    print "Case #%d: %d" % (case_no, NumberOfFairSquardNumbers(first, last));


# # 0 0
# # 1 1
# # 4 2
# # 9 3
# # 121 11
# # 484 22
# # 10201 101
# # 12321 111
# # 14641 121
# # 40804 202
# # 44944 212
# # 1002001 1001
# # 1234321 1111
# # 4008004 2002
