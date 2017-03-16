# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys

# <codecell>

def cmp_scores(c_s1, j_s1, c_s2, j_s2):
    #returns true if c_s2, j_s2 is better than c_s1 j_s1
    d1 = abs(int(c_s1) - int(j_s1))
    d2 = abs(int(c_s2) - int(j_s2))
    if d2 < d1:
        return True
    if d1 < d2:
        return False
    if int(c_s2) < int(c_s1):
        return True
    if (int(c_s2) == int(c_s1)) and ( int(j_s2) < int(j_s1)):
        return True
    return False

def solve(c_str, j_str, flag = 0):
    if c_str == "":
        return "", ""
    c_bigger = False
    j_bigger = False
    unknown = False
    my_flag = flag
    if flag > 0:
        c_bigger = True
    if flag < 0:
        j_bigger = True
    if flag == 0:
        unknown = True
    c_ret = ""
    j_ret = ""
    c = c_str[0]
    j = j_str[0]
    if c_bigger:
        c_tmp, j_tmp = solve(c_str[1:], j_str[1:], flag)
        return (c if c != '?' else '0') + c_tmp, (j if j != '?' else '9') + j_tmp
    if j_bigger:
        c_tmp, j_tmp = solve(c_str[1:], j_str[1:], flag)
        return (c if c != '?' else '9') + c_tmp, (j if j != '?' else '0') + j_tmp
    if c != '?' and j != '?':
        if ((my_flag == 0) and (c != j)):
            if int (c) > int(j):
                my_flag = 1
            else:
                my_flag = -1
        c_tmp, j_tmp = solve(c_str[1:], j_str[1:], my_flag)
        return c + c_tmp, j +j_tmp
    else: 
        c_u, j_u = solve(c_str[1:], j_str[1:], 0)
        if c == j: #both ?
            choice = "0"
        else:
            choice = c if c != '?' else j
        c_ans = choice +c_u            
        j_ans = choice +j_u
            
        if not ((j == '9') or (c == '0')): # in this case, not possible to make c_str bigger
            c_c, j_c = solve(c_str[1:], j_str[1:], 1)
            if c == '?':    
                c_tmp = str(int(choice) + 1) + c_c
                j_tmp = choice + j_c
            else: # j == ?
                c_tmp = choice + c_c
                j_tmp = str(int(choice) -1) + j_c
            if cmp_scores(c_ans, j_ans, c_tmp, j_tmp):
                c_ans = c_tmp
                j_ans = j_tmp
                    
        if not ((j == '0') or (c == '9')):
            c_j, j_j = solve(c_str[1:], j_str[1:], -1)
            if c == '?':
                if j == '?':
                    choice = "1"
                c_tmp = str(int(choice) - 1) + c_j
                j_tmp = choice + j_j
            else: # j == ?
                c_tmp = choice + c_j
                j_tmp = str(int(choice) + 1) + j_j
            if cmp_scores(c_ans, j_ans, c_tmp, j_tmp):
                c_ans = c_tmp
                j_ans = j_tmp
            
    return c_ans, j_ans
        
num = int(sys.stdin.readline())

for n in range(1, num+1):
    c_str, j_str = sys.stdin.readline().split()
    c_ans, j_ans = solve(c_str, j_str, 0)
    print("Case #{0}: {1} {2}".format(n, c_ans, j_ans))
