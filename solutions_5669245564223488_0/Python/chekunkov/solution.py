# -*- coding: utf-8 -*-
# This library is available online and free to use:
# https://github.com/yanatan16/pycodejam
from codejam.parsers import iter_parser

# This library is available online and free to use:
# http://www.numpy.org/
import numpy as np

from itertools import permutations, groupby, chain
from collections import Counter


def solve(*lines):
    # return len(list(permutations(lines)))
    start_chars = Counter()
    end_chars = Counter()
    middle_chars = Counter()
    # print[''.join(groupby(car)) for car in list]
    cars = [''.join(k for k, _ in groupby(car)) for car in lines]
    num_cars = len(cars)
    for car in cars:
        start_char = car[0]
        end_char = car[-1]
        for char in car[1:-1]:
            middle_chars[char] += 1
        start_chars[start_char] += 1
        end_chars[end_char] += 1
    for char, cnt in middle_chars.iteritems():
        if cnt > 1:
            # cannot be adjacent
            return 0
    miss = 0
    combinations = 0
    for char, cnt in start_chars.iteritems():
        if not char in end_chars:
            miss += 1
            if miss > 1:
                # 2 or more cars witch cannot be paired
                return 0
            continue
        combinations += min(cnt, end_chars[char])
        combinations %= 1000000007
    print start_chars
    print end_chars
    print middle_chars
    return combinations

def solve(*lines):
    count = 0
    for perm in permutations(lines):
        chars_seen = set()
        for char, _ in groupby(''.join(perm)):
            if char in chars_seen:
                break
            chars_seen.add(char)
        else:
            # valid train
            count = (count + 1) % 1000000007
    return count





@iter_parser
def parse(nxtline):
    num = int(nxtline())
    cars = nxtline().split()
    assert len(cars) == num
    return cars

if __name__ == "__main__":
    from codejam import CodeJam
    CodeJam(parse, solve).main()
