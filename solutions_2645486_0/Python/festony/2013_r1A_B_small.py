'''
CodeJam Practice 
Created on 2013-04-27

@author: festony
'''

from cj_lib import *
from properties import *

#curr_file_name = 'B-large'
curr_file_name = 'B-small-attempt1'
#curr_file_name = 'B-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        E, R, N = map(int, input_lines.pop(0).split(' '))
        v = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([E, R, N, v])
    return case_inputs

def proc(in_e, E, R, v, out_e):
    max_v = max(v)
    i_max_v = v.index(max_v)
    prev_v = v[:i_max_v]
    after_v = v[i_max_v+1:]
    after_max_e = out_e - R * (len(after_v) + 1)
    if after_max_e < 0:
        after_max_e = 0
    before_max_e = in_e + R * len(prev_v)
    if before_max_e > E:
        before_max_e = E
    r = (before_max_e - after_max_e) * max_v
    if len(prev_v) > 0:
        r += proc(in_e, E, R, prev_v, before_max_e)
    if len(after_v) > 0:
        r += proc(after_max_e + R, E, R, after_v, out_e)
    return r
    
    
def process_func(func_input):
    E, R, N, v = func_input
    if R >= E:
        R = E
        return sum(map(lambda x:x * R, v))
    if R == 0:
        return max(v) * E
#    max_v = max(v)
#    r = max_v * E
#    v.remove(max_v)
#    r += sum(map(lambda x:x * R, v))
    return proc(E, E, R, v, 0)
    
    
    #print func_input
    #return 0

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#print max([3, 4, 5, 6, 7])
