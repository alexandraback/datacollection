'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

curr_file_name = 'A-large'
#curr_file_name = 'A-small-attempt0'
#curr_file_name = 'test'


def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        board = []
        for i in range(4):
            board.append(list(input_lines.pop(0)))
        case_inputs.append(board)
        input_lines.pop(0)
    return case_inputs

def check_line_won(line):
    uniq_elem = list(set(line))
    r = ''
    if len(uniq_elem) == 1:
        r = uniq_elem[0]
    elif len(uniq_elem) == 2:
        if 'T' in uniq_elem:
            t_index = uniq_elem.index('T', )
            winner_index = (t_index + 1) % 2
            r = uniq_elem[winner_index]
        else:
            if '.' in uniq_elem:
                r = '.'
            else:
                r = 'C' #completed
    else:
        if '.' in uniq_elem:
            r = '.'
        else:
            r = 'C'
    return r
    
def process_func(func_input):
    board = func_input
    #rows = board[:]
    completed = True
    for line in board:
        r = check_line_won(line)
        if r == 'X':
            return 'X won'
        if r == 'O':
            return 'O won'
        if completed and r == '.':
            completed = False
            
    columns = []
    for i in range(4):
        column = []
        for j in range(4):
            column.append(board[j][i])
        columns.append(column)
        
    for line in columns:
        r = check_line_won(line)
        if r == 'X':
            return 'X won'
        if r == 'O':
            return 'O won'
        if completed and r == '.':
            completed = False
            
    cross = [[], []]
    for i in range(4):
        cross[0].append(board[i][i])
        cross[1].append(board[i][3-i])
        
    for line in cross:
        r = check_line_won(line)
        if r == 'X':
            return 'X won'
        if r == 'O':
            return 'O won'
        if completed and r == '.':
            completed = False
   # print rows
    #print columns
    #print cross
    if completed:
        return 'Draw'
    return 'Game has not completed'

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#print check_line_won(['X', 'X', 'X', 'X'])
#x = set(['X', 'O', '.'])
#x.index('X')


