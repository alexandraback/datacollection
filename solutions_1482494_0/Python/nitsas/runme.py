#!/usr/bin/env python3.2
"""
Kingdom Rush problem
for Google Code Jam 2012
Round 1A

Link to problem description:
http://code.google.com/codejam/contest/1645485/dashboard#s=p1

author: 
Christos Nitsas
(chrisn654)

language:
Python 3.2.1

date:
April, 2012

usage:
$ python3.2 runme.py sample.in
or
$ runme.py sample.in
(where sample.in is the input file and $ the prompt)
"""


import sys
from operator import itemgetter
# non-standard modules:
from helpful import read_int, read_list_of_int


def read_levels(file, num_levels):
    levels_yielding_one_star = []
    levels_yielding_two_stars = []
    lvl_num = 0
    for one_star_lvl, two_star_lvl in (read_list_of_int(file) for i in range(num_levels)):
        levels_yielding_one_star.append((one_star_lvl, lvl_num))
        levels_yielding_two_stars.append((two_star_lvl, lvl_num))
        lvl_num += 1
    return levels_yielding_one_star, levels_yielding_two_stars


def how_many_complete_levels(levels_yielding_one_star, levels_yielding_two_stars):
    levels_yielding_one_star.sort(key=itemgetter(0))
    levels_yielding_two_stars.sort(key=itemgetter(0))
    stars, levels_completed = 0, 0
    while stars < levels_yielding_two_stars[-1][0]:
        if levels_yielding_two_stars[0][0] <= stars:
            found = remove_level(levels_yielding_one_star, levels_yielding_two_stars[0][1])
            levels_yielding_two_stars.pop(0)
            if found:
                stars += 2
            else:
                stars += 1
            levels_completed += 1
        elif len(levels_yielding_one_star) and levels_yielding_one_star[0][0] <= stars:
            levels_yielding_one_star.pop(0)
            stars += 1
            levels_completed += 1
        else:
            return "Too Bad"
    return levels_completed + len(levels_yielding_two_stars)


def remove_level(levels, level_number):
    for i, (_, lvl_num) in enumerate(levels):
        if lvl_num == level_number:
            levels.pop(i)
            return True
    return False


def main(filename=None):
    if filename is None:
        if len(sys.argv) == 2:
            filename = sys.argv[1]
        else:
            print("Usage: runme.py input_file")
            return 1
    with open(filename, "r") as f:
        num_test_cases = read_int(f)
        for i in range(1, num_test_cases + 1):
            num_levels = read_int(f)
            levels_yielding_one_star, levels_yielding_two_stars = read_levels(f, num_levels)
            print("Case #{0}: {1}".format(i, how_many_complete_levels(levels_yielding_one_star, levels_yielding_two_stars)))
    return 0


if __name__ == "__main__":
    status = main()
    sys.exit(status)

