# -*- coding: utf-8 -*-
"""
Created on Sat May  2 18:24:10 2015

@author: peter
"""

#%% IO
import math

def read_input(fin_name):
    with open(fin_name, 'r') as fin:
        fin.readline()
        for line in fin:
            yield int(line)



def runit(fin_name, fout_name):
    with open(fout_name, 'w') as fout:
        cases = list(read_input(fin_name))
        max_number = 10**(int(math.ceil(math.log(max(cases), 10))))
        counts = compute_counts(max_number)
        for i, case in enumerate(cases, 1):
            fout.write('Case #{}: {}\n'.format(i, proceed(case, counts)))
            
            
#%% proceed

import numpy as np
import Queue


MAX_NUMBER = 10**6

def reverse_number(n):
    acc = 0
    while n > 0:
        acc *= 10
        rest = n % 10
        n = n // 10
        acc += rest
    return acc



def compute_counts(max_number):
    counts = np.zeros((max_number+1,), dtype=np.int32)
    counts[1] = 1
    explore_queue = Queue.PriorityQueue()
    explore_queue.put((1, 1))
    while not explore_queue.empty():
        current_count, current = explore_queue.get()
        if current+1 <= max_number and counts[current+1] == 0:
            counts[current+1] = current_count + 1
            explore_queue.put((current_count + 1, current+1))
        inverse = reverse_number(current)
        if inverse <= max_number and counts[inverse] == 0:
            counts[inverse] = current_count + 1
            explore_queue.put((current_count+1, inverse))
    return counts            

def proceed(case, counts):
    return counts[case]


#%% run test set

runit('A-test.in', 'A-test.out')


#%% run small set

runit('A-small-attempt0.in', 'A-small-attempt0.out')

#%% run big set

runit('A-large.in', 'A-large.out')