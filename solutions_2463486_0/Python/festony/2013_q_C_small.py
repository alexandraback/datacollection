'''
CodeJam Practice 
Created on 2013-04-13

@author: festony
'''

from cj_lib import *
from properties import *
import math

#curr_file_name = 'C-large'
curr_file_name = 'C-small-attempt0'
#curr_file_name = 'test'


def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        case_inputs.append(map(int, input_lines.pop(0).split(' ')))
    return case_inputs

def is_pali(x):
    x_str = str(x)
    r_x_str = x_str[::-1]
    return x_str == r_x_str
    pass
    
def process_func(func_input):
    A, B = func_input
    root_A = int(math.ceil(math.sqrt(A)))
    root_B = int(math.floor(math.sqrt(B)))
    count = 0
    for i in range(root_A, root_B + 1):
        if is_pali(i):
            if is_pali(i*i):
                count += 1
    return count

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#print is_pali(121)


