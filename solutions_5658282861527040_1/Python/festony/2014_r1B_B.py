'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


curr_file_name = 'B-large'
#curr_file_name = 'B-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        A, B, K = map(int, input_lines.pop(0).split(' '))
        case_inputs.append([A, B, K])
    return case_inputs
    
# small
def process_funcy(func_input):
    A, B, K = func_input
    tc = 0
    for i in range(0, A):
        for j in range(0, B):
            if i & j < K:
                tc += 1
    return tc

# large
cache = {}
def calc(a, b, k):
    x = tuple([a, b, k])
    if cache.has_key(x):
        return cache[x]
    tc = 0
    for i in range(0, a+1):
        for j in range(0, b+1):
            if i & j <= k:
                tc += 1
    cache[x] = tc
    return tc

def tobin(i):
    return [int(x) for x in bin(i)[2:]]

def toint(arr):
    return int(''.join(map(str, arr)), 2)

def proc(a, b, k):
    # a always >= b
    if a < b:
        a, b = b, a
    sa = tobin(a)
    sb = tobin(b)
    sk = tobin(k)
    #print 'calculating', sa, sb, sk
    
    if len(sk) > len(sb):
        return (a + 1) * (b + 1)
    
    if len(sa) <= 3:
        return calc(a, b, k)
    
    r = 0
    if len(sa) != len(sb):
        # means len sa > len sb
        nsa1 = sa[1:]
        na1 = toint(nsa1)
        nsa2 = [1] * (len(sa)-1)
        na2 = toint(nsa2)
        
        r += proc(na1, b, k)
        r += proc(na2, b, k)
    else:
        nsb1 = sb[1:]
        nb1 = toint(nsb1)
        nsb2 = [1] * (len(sb)-1)
        nb2 = toint(nsb2)
            
        nsa1 = sa[1:]
        na1 = toint(nsa1)
        nsa2 = [1] * (len(sa)-1)
        na2 = toint(nsa2)
        
            
        if len(sb) > len(sk):
            r += proc(nb2, na2, k)
            r += proc(nb2, na1, k)
            r += proc(nb1, na2, k)
        else:
            nsk = sk[1:]
            nk = toint(nsk)
            r += proc(na2, b, k)
            r += proc(na1, nb2, k)
            r += proc(na1, nb1, nk)
    return r



def process_func(func_input):
    A, B, K = func_input
#    print func_input
#    print tobin(A)
#    print tobin(B)
#    print tobin(K)
    a = A - 1
    b = B - 1
    k = K - 1
#    x = tobin(a)
#    y = toint(x)
#    print a, x, y
    
    tc = proc(a, b, k)
    return tc

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


