#! /usr/bin/python

import os, sys


def initial_state():
    rows = {0:None, 1:None, 2:None, 3:None}
    columns = {0:None, 1:None, 2:None, 3:None}
    diagon = {0:None, 1:None}
    return rows, columns, diagon, False

# valid values : 'X', 'O', 'DRAW', NONE, 'ANY'

def calc(field, old_value):
    if old_value is None and field in ['X', 'O']:
        return field
    elif old_value is None and field == '.':
        return 'DRAW'
    elif old_value is None and field == 'T': #!!! ? sure ?
        return 'ANY'
    elif old_value == 'X' and field in ['X', 'T'] :
        return 'X'
    elif old_value == 'X' and field in ['.', 'O'] :
        return 'DRAW'
    elif old_value == 'O' and field in ['O', 'T'] :
        return 'O'
    elif old_value == 'O' and field in ['.', 'X'] :
        return 'DRAW'
    elif old_value == 'DRAW':
        return 'DRAW'
    elif old_value == 'ANY' and field in ['X', 'O']:
        return field
    elif old_value == 'ANY' and field == '.':
        return 'DRAW'
    elif old_value == 'ANY' and field == 'T':
        return old_value

T = int(sys.stdin.readline())

# For each test case
for t in range(1, T+1):
    rows, columns, diagon, has_empty = initial_state()
    result = None
    # read a line:
    for i in range(0,4):
        for j in range(0,4):
            if result == 'WIN':
                break
            d = sys.stdin.read(1)
            if d == '.':
                has_empty = True
                
            rows[i] = calc(d, rows[i])
            columns[j] = calc(d, columns[j])
            if i==j:
                diagon[0] = calc(d, diagon[0])
            elif i+j == 3:
                diagon[1] = calc(d, diagon[1])
        sys.stdin.read(1)
    sys.stdin.readline()

    if 'X' in rows.values():
        sys.stdout.write('Case #%s: X won\n' % (t))
        result = 'WIN'
    elif 'O' in rows.values():
        sys.stdout.write('Case #%s: O won\n' % (t))
        result = 'WIN'
    elif 'X' in columns.values() or 'X' in diagon.values() and result is None:
        sys.stdout.write('Case #%s: X won\n' % (t))
        result = 'WIN'
    elif 'O' in columns.values() or 'O' in diagon.values() and result is None:
        sys.stdout.write('Case #%s: O won\n' % (t))
        result = 'WIN'

    if result is None and has_empty:
        sys.stdout.write('Case #%s: Game has not completed\n' % (t))
    elif result is None:
        sys.stdout.write('Case #%s: Draw\n' % (t))
