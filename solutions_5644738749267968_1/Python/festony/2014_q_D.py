'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


curr_file_name = 'D-large'
#curr_file_name = 'D-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        input_lines.pop(0)
        N = map(float, input_lines.pop(0).split(' '))
        K = map(float, input_lines.pop(0).split(' '))
        case_inputs.append([N, K])
    return case_inputs
    
def process_func(func_input):
    print func_input
    N, K = func_input
    n = sorted(N, reverse=True)
    k = sorted(K)
    normal = 0
    for i in n:
        got = -1
        for j in k:
            if j > i:
                got = j
                break
        if got < 0:
            normal += 1
            k.pop(0)
        else:
            k.remove(got)
    n = sorted(N)
    k = sorted(K)
    cheat = 0
    for i in k:
        got = -1
        for j in n:
            if j > i:
                got = j
                break
        if got > 0:
            cheat += 1
            n.remove(got)
        else:
            n.pop(0)
    return ' '.join([str(cheat), str(normal)])

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


