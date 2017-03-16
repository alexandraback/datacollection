'''
CodeJam Practice 
Created on 2013-04-13

@author: festony
'''

from cj_lib import *
from properties import *
import math

curr_file_name = 'C-large-1'
#curr_file_name = 'C-small-test'
#curr_file_name = 'test'

def is_pali(x):
    x_str = str(x)
    r_x_str = x_str[::-1]
    return x_str == r_x_str
    
c = 0
p = []
p_2 = []
for i in range(1, 10000001):
    if is_pali(i):
        p.append(i)
        if is_pali(i*i):
            p_2.append(i*i)
            c += 1

print c
#print p

def find_range(arr, r):
    start = -1
    end = len(arr)
    for i, x in enumerate(arr):
        if x < r[0]:
            start = i
        if x > r[1]:
            end = i
            break
    return end - start - 1
#    l = len(arr)
#    start = 0
#    end = l
#    while start < end-1:
#        if v < arr[start + 1]:
#            return start
#        if v > arr[end - 1]:
#            return end
#        if v > arr[end - 2]:
#            return end - 1
#        mid = (start + end) / 2
#        if v == arr[mid]:
#            return mid
#        if v > arr[mid]:
#            start = mid + 1
#            continue
#        if v < arr[mid]:
#            end = mid
#            continue
#    return start


def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        case_inputs.append(map(int, input_lines.pop(0).split(' ')))
    return case_inputs

def process_func(func_input):
    A, B = func_input
    return find_range(p_2, [A,B])

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#print is_pali(121)

#def generate_pali_from_half(first_half_digits, total_digit_len):
#    digits = first_half_digits[:]
#    if total_digit_len == len(first_half_digits) * 2:
#        digits += reversed(first_half_digits)
#    else:
#        digits += reversed(first_half_digits)[1:]
#    return int(str(''.join(map(str, digits))))
#
#def generate_all_pali(digit_len):
#    if digit_len == 1:
#        return [1,2,3,4,5,6,7,8,9]
#    half_len = int(math.ceil(digit_len / 2.0))
#    half_len
#    return []


#print generate_pali_from_half([1, 2, 3], 6)

#p2 = generate_all_pali(5)

#print find_range([1,4,7], [0, 8])
