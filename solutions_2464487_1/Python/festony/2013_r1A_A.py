'''
CodeJam Practice 
Created on 2013-04-27

@author: festony
'''

from cj_lib import *
from properties import *

import math

curr_file_name = 'A-large'
#curr_file_name = 'A-small-attempt1'
#curr_file_name = 'test'


# map(int, input_lines.pop(0).split(' '))



# assume can draw x circles, then we have:
# 2x(x-1) + (2r+1)x <= t
# namely:
# 2x^2 + (2r-1)x - t <= 0
# knowing x > 1, we have:
# x = [1-2r + sqrt((2r-1)^2 + 8t)] / 4

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        r, t = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([r, t])
    return case_inputs
    
def calc_total(x, r):
    return 2 * x * x + (2 * r - 1) * x

def process_func(func_input):
    r, t = func_input
    x = (1-2*r) / 4 + math.floor((math.sqrt((2*r-1)*(2*r-1) + 8*t)) / 4)
    while calc_total(x, r) <= t:
        x += 1
    while calc_total(x, r) > t:
        x -= 1
    return int(x)

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


