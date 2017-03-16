#!/usr/bin/env python
import sys


def solve_case(case_str):
    right_most = len(case_str)
    left_most = 0
    while case_str[right_most-1] == '+' and right_most > 0:
        # ignore right +
        #             <      <
        # +++---+-----+++++++
        right_most -= 1
    if right_most == 0:
        # all are fine
        # <            <
        # +++++++++++++
        return 0
    while case_str[left_most] == '+' and left_most < right_most:
        # move over left +
        #             <      <
        #    >
        # +++---+-----+++++++
        #     <      <
        #    >
        # +++-++++++++
        left_most += 1
    groups = 0
    current = case_str[left_most]
    while left_most < right_most:
        # count the number of groups in the middle
        left_most += 1
        if left_most == len(case_str):
            groups += 1
            break
        if case_str[left_most] != current:
            groups += 1
            current = case_str[left_most]
    if case_str[0] == '+':
        groups += 1
    return groups





if __name__ == '__main__':
    case_count = int(sys.stdin.readline())
    for i in xrange(1, case_count+1):
        case_str = sys.stdin.readline().strip()
        solution = solve_case(case_str)
        print 'Case #{}: {}'.format(i, solution)

