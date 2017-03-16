import itertools
import re

import sys


def find_solution(arr):
    ordered = []
    count = 0
    current = list(arr)
    while True:
        has_fake = False
        for x in current:
            left_set = set()
            right_set = set()

            x_split = x.split()
            x_left = x_split[0]
            x_right = x_split[1]

            # print(x_left, x_right)
            for y in current:
                if x == y:
                    continue
                y_split = y.split()
                left_set.add(y_split[0])
                right_set.add(y_split[1])

            # print(left_set, right_set)
            if x_left in left_set and x_right in right_set:
                current.remove(x)
                ordered.append(x)
                count += 1
                has_fake = True
        if not has_fake:
            break
    # print(ordered)
    return count


def test():
    print("---Start Test---")

    test_cases_in = [
        ['HYDROCARBON COMBUSTION', 'QUAIL BEHAVIOR', 'QUAIL COMBUSTION'],
        ['CODE JAM', 'SPACE JAM', 'PEARL JAM'],
        ['INTERGALACTIC PLANETARY', 'PLANETARY INTERGALACTIC'],
        ['C B', 'C D', 'A B']
    ]
    test_cases_out = [
        1,
        0,
        0,
        1
    ]

    for i in range(len(test_cases_in)):
        solution = find_solution(test_cases_in[i])
        try:
            assert (solution == test_cases_out[i])
        except:
            print("%d : expected %s, but actual %s" %
                  (i, test_cases_out[i], solution))

    print("---End Test---")

#test()

T = int(input())

for t in range(T):
    N = int(input())
    input_str = [input() for x in range(N)]
    solution = find_solution(input_str)

    output_text = "Case #{}: {}".format(t + 1, solution)
    print(output_text)
