#!/usr/bin/env python3

import sys
import itertools


def best_result(num_kids, bffs):
    kids = range(num_kids)
    best_so_far = 0

    for circle_size in range(2, num_kids + 1):
        for combo in itertools.combinations(kids, circle_size):
            for perm in itertools.permutations(combo):
                if are_all_kids_satisfied(bffs, perm):
                    best_so_far = circle_size
                    break

            if best_so_far == circle_size:
                break

    return best_so_far

def are_all_kids_satisfied(bffs, perm):
    num = len(perm)

    for i, kid in enumerate(perm):
        bff = bffs[kid]
        left = (i - 1 + num) % num
        right = (i + 1) % num

        if perm[left] == bff or perm[right] == bff:
            pass # ok
        else:
            return False

    return True


num_tests = int(sys.stdin.readline().strip())

for i in range(num_tests):
    num_kids = int(sys.stdin.readline().strip())

    bffs = {}
    line = sys.stdin.readline().strip()
    for kid_index, bff in enumerate(line.split(" ")):
        bffs[kid_index] = int(bff.strip()) - 1

    print("Case #%d: %s" % (i+1, best_result(num_kids, bffs)))

