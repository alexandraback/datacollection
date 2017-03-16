'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


curr_file_name = 'A-large'
#curr_file_name = 'A-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        ln = input_lines.pop(0).split(' ')
        Smax = int(ln[0])
        SS = map(int, list(ln[1]))
        case_inputs.append([Smax, SS])
    return case_inputs
    
def process_func(func_input):
    Smax, SS = func_input
    
    f = 0
    o = 0
    for i in range(Smax + 1):
        cur = SS[i]
        if i > o:
            f += i - o
            o = i
        o += cur
    
    return f

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


