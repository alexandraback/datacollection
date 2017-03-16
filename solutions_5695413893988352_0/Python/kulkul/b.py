import itertools
import re

import sys


def find_solution(arr):
    # print(arr)
    ques_count = arr.count('?')

    min_diff = sys.maxsize
    min_left = '0'
    min_right = '0'
    for i in itertools.product([0,1,2,3,4,5,6,7,8,9], repeat=ques_count):
        arr_insert = str(arr)
        for j in range(ques_count):
            arr_insert = arr_insert.replace('?', str(i[j]), 1)
        # print(arr_insert)

        left_str = arr_insert.split(' ')[0]
        left = int(arr_insert.split(' ')[0])
        right_str = arr_insert.split(' ')[1]
        right = int(arr_insert.split(' ')[1])
        diff = abs(left - right)
        if abs(left - right) < min_diff:
            min_diff = diff
            min_left = left_str
            min_right = right_str
        elif abs(left - right) == min_diff and int(min_right) > int(right_str):
            min_left = left_str
            min_right = right_str

    return min_left + ' ' + min_right



def test():
    print("---Start Test---")

    test_cases_in = [
        '1? 2?',
        '?2? ??3',
        '? ?',
        '?5 ?0',
    ]
    test_cases_out = [
        '19 20',
        '023 023',
        '0 0',
        '05 00',
    ]

    for i in range(len(test_cases_in)):
        solution = find_solution(test_cases_in[i])
        try:
            assert (solution == test_cases_out[i])
        except:
            print("%d : expected %s, but actual %s" %
                  (i, test_cases_out[i], solution))

    print("---End Test---")

# test()

T = int(input())

for t in range(T):
    solution = find_solution(input())

    output_text = "Case #{}: {}".format(t + 1, solution)
    print(output_text)
