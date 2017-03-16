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
curr_file_name = 'B-small-attempt5'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        D = int(input_lines.pop(0))
        P = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([D, P])
    return case_inputs

def score_S(S):
    #print 'score ', S[0] + max(S[1])
    return S[0] + max(S[1])

# def test(P, t):
#     if t < len(P):
#         return None
#     s = sum(P)
#     rl = int(math.ceil(float(s) / t))
#     target = [rl] * (t-1)
#     target.append(s-sum(target))
#     print target

def test(P, th):
    if th >= max(P):
        return max(P)
    cut = 0
    for p in P:
        if p > th:
            for test_cut in range(1, p+1):
                if int(math.ceil(float(p) / test_cut)) <= th:
                    cut += test_cut - 1
                    break
    return cut + th
    
def process_func(func_input):
    D, P = func_input
    
    T = 0
    P.sort(reverse = True)
    init_S = [T, P]
    
#     print P
#     print test(P, 1)
    min_t = 1000000;
    for i in range(1, max(P)+1):
        t = test(P, i)
        print P, i, t
        if t < min_t:
            min_t = t
    
    return min_t

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


