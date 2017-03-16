__author__ = 'barbapapa'
from collections import *
import pickle
import itertools as itt
import numpy as np
import math


def read_input(f_name):
    cases = []
    with open(f_name) as f:
        nr_cases = int(f.readline().strip())
        for c in range(nr_cases):
            A, B, K = [int(x) for x in f.readline().strip().split()]
            cases.append((A, B, K))
    return cases

def write_output(f_name, results):
    with open(f_name, 'w') as f:
        for i, r in enumerate(results):
            f.write('Case #'+str(i+1)+': '+r+'\n')

def solve_case(data):
    A, B, K = data
    count = 0
    for i in range(A):
        for j in range(B):
            if i&j < K:
                count += 1
    print str(count)
    return str(count)


#file_name = 'B-test'
file_name = 'B-small-attempt0'
#file_name = 'B-large'
cases = read_input(file_name+'.in')
solution = [solve_case(x) for x in cases]
write_output(file_name+'.out', solution)
