'''
CodeJam Practice 
Created on 2013-04-13

@author: festony
'''

from cj_lib import *
from properties import *

curr_file_name = 'B-large'
#curr_file_name = 'B-small-attempt0'
#curr_file_name = 'test'


def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        N, M = map(int, input_lines.pop(0).split(' '))
        lawn = []
        for i in range(N):
            lawn.append(map(int, input_lines.pop(0).split(' ')))
        case_inputs.append([N, M, lawn])
    return case_inputs
    
def process_func(func_input):
    N, M, lawn = func_input
    verticle_max = []
    for line in lawn:
        verticle_max.append(max(line))
        
    columns = []
    for i in range(M):
        column = []
        for j in range(N):
            column.append(lawn[j][i])
        columns.append(column)
    #print columns
    horizontal_max = []
    for line in columns:
        horizontal_max.append(max(line))
        
    #print verticle_max
    #print horizontal_max
    
    for i in range(N):
        for j in range(M):
            if lawn[i][j] < verticle_max[i] and lawn[i][j] < horizontal_max[j]:
                return 'NO'
    
    return 'YES'

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


