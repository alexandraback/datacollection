# -*- coding: utf-8 -*-
"""

@author: Robo
"""

import os
import numpy as np

folder = "D:/CODE/googlecodejam/bleatrix"
infile = "A-small-attempt0.in"
outfile = "A-small-attempt0.out"


def read_gcj_input():
    cases = []
    with open(os.path.join(folder,infile), 'r') as f:
        for each in xrange(int(f.readline())):
            Araw = f.readline().strip()
            cases.append(int(Araw))
    return cases
    

def check_digits(num, count_array):
    num_list = list(set([int(s) for s in str(num)]))
    for thisnum in num_list:
        count_array[thisnum] = 1
    return count_array
    
    
    

def multi_and_count(N):
    count_array = np.zeros(10)
    thismulti = 0
    while sum(count_array)<10:
        thismulti = thismulti+N
        count_array = check_digits(thismulti,count_array)
    return thismulti        
    
cases = read_gcj_input()


with open(os.path.join(folder,outfile), 'w') as f:
    for index,case in enumerate(cases):
        N = case
        if N==0:
            result = 'INSOMNIA'
        else: 
            result = multi_and_count(N)
        f.write('Case #{0}: {1}\n'.format(index+1,result))
