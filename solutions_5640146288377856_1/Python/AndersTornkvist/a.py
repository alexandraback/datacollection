#!/usr/bin/python

import os
import sys
import re
import math


def solve(R, C, W):
    per_row = int(math.floor(C / W))
    to_right = C - per_row * W
    find_all = W
    if not to_right:
        find_all -= 1
    answer = per_row * R + find_all
    return answer
    

def find_input_and_output_files():
    files = sorted(list(filter(os.path.isfile, os.listdir('.'))), reverse=True)
    patterns = ['^[A-Z]-large(-(attempt\d?|practice(-\d)?))?\.in$', '^[A-Z]-small(-(attempt\d?|practice(-\d)?))?\.in$', '^sample\.in$']
    for pattern in patterns:
        prog = re.compile(pattern)
        for file in files:
            if prog.match(file):
                return (file, re.sub('\.in$', '', file) + '.out')
    return ('input.in', 'output.out')

def multiple_N_and_repeat_x_lines(f, x=None, split_lines=False, map_func=None):
    all_N = read_line(f, split_lines=True, map_func=int)
    all_lines = []
    for N in all_N:
        current_x = N if x is None else x
        all_lines.append(read_x_lines(f, current_x, split_lines, map_func))
    return (all_N, all_lines)

def repeat_N_and_x_lines(f, x=None, split_lines=False, map_func=None, repeat=2):
    all_N = []
    all_lines = []
    for i in range(repeat):
        N, lines = read_N_and_x_lines(f, x, split_lines, map_func)
        all_N.append(N)
        all_lines.append(lines)
    return (all_N, all_lines)

def read_N_and_x_lines(f, x=None, split_lines=False, map_func=None):
    N = read_line(f, map_func=int)
    if x is None:
        x = N
    return (N, read_x_lines(f, x, split_lines, map_func))

def read_line(f, split_lines=False, map_func=None):
    return read_x_lines(f, 1, split_lines, map_func)[0]

def read_x_lines(f, x=1, split_lines=False, map_func=None):
    lines = []
    if split_lines==True:
        split_lines = ' '
    for j in range(x):
        line = f.readline().rstrip('\n')
        if split_lines:
            line = line.split(split_lines)
            if map_func is not None:
                line = list(map(map_func, line))
        elif map_func is not None:
            line = map_func(line)
        lines.append(line)
    return lines

def read_custom(f):
    B, N = read_line(f, True, int)
    speed = read_line(f, True, int)
    return (B, N, speed)

def main():
    input_filename, output_filename = find_input_and_output_files()
    print(input_filename, output_filename)
    with open(input_filename, 'r') as f:
        with open(output_filename, 'w') as o:
            T = int(f.readline().rstrip('\n'))
            for i in range(1, T+1):
#                input_vars = read_line(f, split_lines=True, map_func=float)
#                input_vars = read_line(f, split_lines=True, map_func=int)
#                input_vars = read_N_and_x_lines(f, x=2, split_lines=True, map_func=float)
#                input_vars = read_N_and_x_lines(f)
                input_vars = read_line(f, True, int)
#                input_vars = multiple_N_and_repeat_x_lines(f, split_lines=True, map_func=int) # multiple Ns on first row, followed by N1 rows, N2 rows
#                input_vars = read_line(f, split_lines='/', map_func=int) # fraction
#                input_vars = read_N_and_line(f, split_lines=True, map_func=int)
#                input_vars = read_custom(f)
                result = solve(*input_vars)
                to_output = "Case #" + str(i) + ": " + str(result)
                print(to_output)
                o.write(to_output + "\n")

if __name__=="__main__":
    main()
