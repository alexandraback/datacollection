# -*- coding: utf-8 -*-
"""
Created on Sat May  2 18:24:10 2015

@author: peter
"""

#%% IO
def read_input(fin_name):
    with open(fin_name, 'r') as fin:
        nb_cases = int(fin.readline())
        for _ in xrange(nb_cases):
            n = int(fin.readline())
            groups = []
            for _ in xrange(n):
                d, h, m = map(int, fin.readline().split())
                groups.append((d, h, m))
            yield (n, groups)

def runit(fin_name, fout_name, **kwargs):
    with open(fout_name, 'w') as fout:
        for i, case in enumerate(read_input(fin_name), 1):
            fout.write('Case #{}: {}\n'.format(i, proceed(case, **kwargs)))
            
            
#%% proceed

ROUND = 360
import fractions

def proceed(case):
    n, groups = case
    hikers = sum(h for _, h, _ in groups)
    min_cross = hikers
    max_cross = hikers
    arrivals = []
    for d, h, m in groups:
        first_arrival_degree = ROUND - d
        for minute in xrange(m, m+h):
            current_arrival_time = fractions.Fraction(minute * first_arrival_degree, ROUND)
            current_arrival_degree = first_arrival_degree
            for nb_round in xrange(hikers+1):
                arrivals.append((current_arrival_time, current_arrival_degree))
                current_arrival_degree += ROUND
                current_arrival_time += minute
    arrivals.sort()
    current_cross = hikers
    index = 0
    while index < len(arrivals):
        current_time = arrivals[index][0]
        while index < len(arrivals) and arrivals[index][0] == current_time:
            degree = arrivals[index][1]
            if degree < ROUND:
                current_cross -= 1
            else:
                current_cross += 1
            index += 1 
        if current_cross < min_cross:
            min_cross = current_cross
    return min_cross


#%% run test set

runit('C-test.in', 'C-test.out')


#%% run small set

runit('C-small-1-attempt2.in', 'C-small-1-attempt2.out')

#%% run small set

runit('C-small-2-attempt0.in', 'C-small-2-attempt0.out')

#%% run big set

runit('C-large.in', 'C-large.out')