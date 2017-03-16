'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = '-large-practice'
curr_file_name = 'C-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        L, X = map(int, input_lines.pop(0).split(' '))
        s = input_lines.pop(0)
        
        case_inputs.append([X, s])
    return case_inputs

calc_tab = {
            'ii': [-1, ''],
            'jj': [-1, ''],
            'kk': [-1, ''],
            'ij': [1, 'k'],
            'ji': [-1, 'k'],
            'jk': [1, 'i'],
            'kj': [-1, 'i'],
            'ki': [1, 'j'],
            'ik': [-1, 'j']
            }

def reduce_1(S):
    p, s = S
    if len(s) > 1:
        r = calc_tab[s[:2]]
        s = r[1] + s[2:]
        p *= r[0]
    return [p, s]
        
    
def process_func(func_input):
    #print len(func_input)
    X, s = func_input
    print X, s
    
    ls = list(s)
    ss = set(ls)
    if len(ss) == 1:
        return 'NO'
    
    init_S = [1, s]
    fin_S = reduce_1(init_S)
    while len(fin_S[1]) >= 2:
        fin_S = reduce_1(fin_S)
    print fin_S
    
    if fin_S[0] == 1:
        if fin_S[1] == '':
            return 'NO'
        else:
            # possible
            if X % 4 == 2:
                # possible
                # i * i = -1
                pass
            else:
                return 'NO'
    else:
        if fin_S[1] == '':
            # possible
            if X % 2 == 1:
                # possible
                # -1
                pass
            else:
                return 'NO'
        else:
            if X % 4 == 2:
                # possible
                # -i * -i = -1
                pass
            else:
                return 'NO'
    
    p = init_S[0]
    s = init_S[1][:]
    X -= 1
    did = ''
    
    while s[0] != 'i':
        if len(s) < 2:
            if X == 0:
                return 'NO'
            X -= 1
            s += init_S[1]
        p, s = reduce_1([p, s])
    
    did = 'i'
    s = s[1:]
    if len(s) < 1:
        if X == 0:
            return 'NO'
        X -= 1
        s += init_S[1]
        
    while s[0] != 'j':
        if len(s) < 2:
            if X == 0:
                return 'NO'
            X -= 1
            s += init_S[1]
        p, s = reduce_1([p, s])
    
    did = 'ij'
    s = s[1:]
    if len(s) < 1:
        if X == 0:
            return 'NO'
        X -= 1
        s += init_S[1]
        
    while s[0] != 'k':
        if len(s) < 2:
            if X == 0:
                return 'NO'
            X -= 1
            s += init_S[1]
        p, s = reduce_1([p, s])
    
    return 'YES'

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


