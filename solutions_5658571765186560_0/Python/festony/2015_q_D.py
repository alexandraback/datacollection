'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'D-large'
curr_file_name = 'D-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        case_inputs.append(map(int, input_lines.pop(0).split(' ')))
    return case_inputs
    
def process_func(func_input):
    X, R, C = func_input
    # make R always smaller
    if R > C:
        R, C = C, R
    if X >= 7:
        return 'RICHARD'
    if X == 1:
        return 'GABRIEL'
    if X >= 4 and R <= 2:
        return 'RICHARD'
    if X >= 3 and R <= 1:
        return 'RICHARD'
    if R*C < X:
        return 'RICHARD'
    if R*C % X != 0:
        return 'RICHARD'
    return 'GABRIEL'

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


