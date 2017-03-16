'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'C-large-practice'
curr_file_name = 'C-small-attempt4'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        case_inputs.append(map(int, input_lines.pop(0).split(' ')))
    return case_inputs

def check_r(b, min_s, R, C):
    r = ''
    arr = []
    if b == 0:
        r = 'Yes!'
        arr = []
    elif b == 1:
        r = 'Yes!'
        arr = [1]
    elif b == 2:
        r = 'NO!'
        arr = []
    elif b == 3:
        r = 'NO!'
        arr = []
    elif b == 4:
        r = 'Yes!'
        if min_s >= 2:
            arr = [2, 2]
        else:
            if C == 1:
                arr = [1,1,1,1]
            else:
                arr = [4]
    elif b == 5:
        r = 'NO!'
        arr = []
    elif b == 6:
        r = 'Yes!'
        if min_s > 2:
            arr = [2, 2, 2]
        elif min_s == 2:
            if C == 2:
                arr = [2,2,2]
            else:
                arr = [3,3]
        else:
            if C == 1:
                arr = [1,1,1,1,1,1]
            else:
                arr = [6]
    elif b == 7:
        r = 'NO!'
        arr = []
    else:
        if min_s > 2:
            r = 'Yes!'
            if b % 2 == 0:
                for i in range(b/2):
                    arr.append(2)
            else:
                b -= 9
                arr = [3,3,3]
                for i in range(b/2):
                    arr.append(2)
        else:
            if min_s == 1:
                r = 'Yes!'
                for i in range(b):
                    arr.append(1)
            else:
                if b % 2 == 0:
                    r = 'Yes!'
                    for i in range(b/2):
                        arr.append(2)
                else:
                    r = 'NO!'
                    arr = []
    return r, arr

def get_r(B, S, min_s, R, C):
    a = B / S
    b = B % S
    r = ''
    arr = []
    if a == 0:
        print 'a == 0'
        r, arr = check_r(b, min_s, R, C)
    elif a == 1:
        print 'a == 1'
        r, arr = check_r(a*S+b, min_s, R, C)
    else:
        print 'a > 1'
        if b == 0:
            r = 'Yes!'
            for i in range(S):
                arr.append(a)
        elif b == 1:
            if S == 2:
                r = 'NO!'
                arr = []
            else:
                if a == 2:
                    #r = 'NO!' # <==== WRONG!
                    #arr = []
                    r, arr = check_r(a*S+b, min_s, R, C)
                else:
                    r = 'Yes!'
                    for i in range(S):
                        arr.append(a)
                    arr[0] += 1
                    arr[1] += 1
                    arr[-1] -= 1
                    
        else:
            r = 'Yes!'
            for i in range(S):
                arr.append(a)
            for i in range(b):
                arr[i] += 1
    return r, arr

def isstar(m, r, c):
    if r < 0 or c < 0:
        return 0
    if r >= len(m) or c >= len(m[0]):
        return 0
    if m[r][c] == '*':
        return 1
    return 0

def countstar(m, r, c):
    if r < 0 or c < 0:
        return
    if r >= len(m) or c >= len(m[0]):
        return
    if m[r][c] != '.' and  m[r][c] != 'c':
        return
    cnt = 0
    cnt += isstar(m, r-1, c-1)
    cnt += isstar(m, r-1, c)
    cnt += isstar(m, r-1, c+1)
    cnt += isstar(m, r, c-1)
    cnt += isstar(m, r, c+1)
    cnt += isstar(m, r+1, c-1)
    cnt += isstar(m, r+1, c)
    cnt += isstar(m, r+1, c+1)
    m[r][c] = str(cnt)
    #print r, c, cnt

def verify(B, R, C, m):
    print '\n' + '\n'.join(map(lambda x:''.join(x), m))
    if len(m[0]) != C:
        print '-----', 'C error!'
    if len(m) != R:
        print '-----', 'R error!'
    c_s = 0
    for i in range(R):
        for j in range(C):
            if m[i][j] == '*':
                c_s += 1
    if c_s != R * C - B:
        print '-----', 'star number error!'
    while True:
        for i in range(R):
            for j in range(C):
                if m[i][j] == 'c':
                    countstar(m, i, j);
                    break
        stillzero = False
        for i in range(R):
            for j in range(C):
                if m[i][j] == '0':
                    stillzero = True
                    m[i][j] = 'o'
                    countstar(m, i-1, j-1)
                    countstar(m, i-1, j)
                    countstar(m, i-1, j+1)
                    countstar(m, i, j-1)
                    countstar(m, i, j+1)
                    countstar(m, i+1, j-1)
                    countstar(m, i+1, j)
                    countstar(m, i+1, j+1)
        if not stillzero:
            break
    print '\n' + '\n'.join(map(lambda x:''.join(x), m))
    for i in range(R):
        for j in range(C):
            if m[i][j] == '.':
                print '-----', 'not one time error! - ', i, j

    
    
def process_func(func_input):
    #print func_input
    R, C, M = func_input
    B = R*C-M
    print B, R, C
    min_s = min(R, C)
    #S = R
    #a = B / S
    #b = B % S
    r, arr = get_r(B, R, min_s, R, C)
    s = 'R'
    if r != 'Yes!':
        #print 'R failed'
        r, arr = get_r(B, C, min_s, R, C)
        s = 'C'
    if r != 'Yes!':
        return '\nImpossible'#,R,C,M,B
    
    #print arr
    m = []
    if s == 'R':
        for i in range(R):
            ln = []
            for j in range(C):
                c = '*'
                if i < len(arr) and j < arr[i]:
                    c = '.'
                ln.append(c)
            m.append(ln)
    else:
        for i in range(R):
            ln = []
            for j in range(C):
                c = '*'
                if j < len(arr) and i < arr[j]:
                    c = '.'
                ln.append(c)
            m.append(ln)
    if m[0][0] == '.':
        m[0][0] = 'c'
    #print m
    #verify(B, R, C, m)
    
    
    rs = '\n' + '\n'.join(map(lambda x:''.join(x), m))
    print rs
    return rs
    #return str(R) + ' ' + str(C) + ' ' + str(M) + ' ' + str(B) + '\n' + rs

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


