# -*- coding: utf-8 -*-

import sys
from utools import files
import itertools


def process(c: str, j: str):

    possible_c = []
    if "?" in c:
        for r in itertools.product('0123456789', repeat=c.count("?")):
            c2 = c
            for rs in r:
                c2 = c2.replace("?", rs, 1)
            possible_c.append(c2)
    else:
        possible_c = [c]
    possible_j = []
    if "?" in j:
        for r in itertools.product('0123456789', repeat=j.count("?")):
            j2 = j
            for rs in r:
                j2 = j2.replace("?", rs, 1)
            possible_j.append(j2)
    else:
        possible_j = [j]

    min_diff = -1
    min_j = -1
    min_c = -1
    for c2 in possible_c:
        for j2 in possible_j:
            diff = abs(int(c2) - int(j2))
            if min_diff < 0 or diff < min_diff:
                min_diff = diff
                min_j = j2
                min_c = c2
            elif diff == min_diff:
                if int(c2) < int(min_c):
                    min_c = c2
                    min_j = j2
                elif int(c2) == int(min_c):
                    if int(j2) < int(min_j):
                        min_c = c2
                        min_j = j2

    return " ".join((min_c, min_j))




def main(path):

    with open(path) as f:
        t = files.read_item(f, int)
        for i in range(1, t+1):
            c, j = files.read_mutiple_items(f, tuple, str)
            result = process(c, j)
            print("Case #{}: {}".format(i, result))


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_input_file>")
    else:
        main(sys.argv[1])
