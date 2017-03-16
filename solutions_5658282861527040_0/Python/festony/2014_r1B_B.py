'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'B-large'
curr_file_name = 'B-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        A, B, K = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([A, B, K])
    return case_inputs
    
# small
def process_func(func_input):
    A, B, K = func_input
    tc = 0
    for i in range(0, A):
        for j in range(0, B):
            if i & j < K:
                tc += 1
    return tc

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


