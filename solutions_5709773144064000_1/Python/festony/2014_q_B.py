'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


curr_file_name = 'B-large'
#curr_file_name = 'B-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        case_inputs.append(map(float, input_lines.pop(0).split(' ')))
    return case_inputs
    
def process_func(func_input):
    print func_input
    C, F, X = func_input
    T = 0
    v = 2.0
    t1 = 0
    t2 = 0
    t3 = 0
    while True:
        #print T, v
        t1 = C/v
        t2 = X/v
        t3 = X/(v+F) + t1
        #print t1, t2, t3
        if t1 >= t2:
            break
        if t3 >= t2:
            break
        T += t1
        v = v+F
    
    return T + t2

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


