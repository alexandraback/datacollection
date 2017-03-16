'''
CodeJam Practice 
Created on 2013-04-27

@author: festony
'''

from cj_lib import *
from properties import *

import math
from operator import mul


#curr_file_name = 'C-large'
curr_file_name = 'C-small-1-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        R, N, M, K = map(int, input_lines.pop(0).split(' '))
        r = []
        for i in range(R):
            r.append(map(int, input_lines.pop(0).split(' ')))
        case_inputs.append([R, N, M, K, r])
    return case_inputs

def gen_all_prod(ori_set):
    total = int(math.pow(2, len(ori_set)))
    possible = []
    
    for i in range(1, total):
        b = reversed(bin(i)[2:])
        temp = [0] * len(ori_set)
        for i, c in enumerate(list(b)):
            if c == '1':
                temp[i] = 1
        #print temp
        
        #print map(lambda x:x[0]*x[1], zip(*[ori_set, temp]))
        possible.append(reduce(mul, filter(lambda x:x != 0, map(lambda x:x[0]*x[1], zip(*[ori_set, temp]))), 1))
        
    return set(possible)
        

def verify_product(ori_set, product, products):
#    while product != 1:
#        mod_able = False
#        for n in ori_set:
#            if product % n == 0:
#                product /= n
#                mod_able = True
#                break
#        if not mod_able:
#            return False
#    return True

    if product == 1:
        return True
    pass
        

def verify_sets(ori_set, prod_set, all_prod_set):
#    for p in prod_set:
#        if not verify_product(ori_set, p, products):
#            return False
#    return True
    ps = set(prod_set)
    if 1 in ps:
        ps.remove(1)
    if len(ps) == 0:
        return True
    if ps.difference(all_prod_set) != set([]):
        return False
    return True
    
    
def process_func(func_input):
    R, N, M, K, r = func_input
    # generate all possible sets
    all_sets = [[]]
    temp = []
    for i in range(N):
        temp = []
        t_s = []
        for s in all_sets:
            for j in range(2, M+1):
                t_s = s[:]
                t_s.append(j)
                temp.append(t_s)
        all_sets = temp
    # print all_sets
    products = {}
    for s in all_sets:
        products[tuple(s)] = gen_all_prod(s)
    res = ''
    for p_s in r:
        for o_s in all_sets:
            if verify_sets(o_s, p_s, products[tuple(o_s)]):
                res+= '\n' + ''.join(map(str, o_s))
                break
    return res

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)

#print verify_product([4, 3, 5], 420)

#print gen_all_prod([2, 2, 4])
#print verify_sets([2, 2, 4], [8, 16, 32], gen_all_prod([2, 2, 4]))
