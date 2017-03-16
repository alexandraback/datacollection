
# coding: utf-8

# In[149]:

from __future__ import division
import fileinput
import math
import subprocess
import time
import numpy as np;
import timeit;
from primesieve import *
import random
import sys;

#f = open("B-large.in", "r");
#f = open("B-small-attempt1.in", "r");
#f = open("test_input.in", "r");


# In[158]:

from primesieve.numpy import *
give_up_threshold=1000;
early_primes = generate_n_primes_array(give_up_threshold)


# In[161]:

#early_primes


# In[162]:

def get_result(y):
    return [sum([int(x2)*b**(x1) for (x1,x2) in enumerate(reversed(list(y)))])  for b in np.arange(2,11, dtype='object')];

def are_there_primes(list_of_numbers):
    for x in list_of_numbers:
        if len(generate_primes(x,x)) > 0:
            return True;
    return False;

def get_factors(list_of_numbers):
    return [one_factor(x) for x in list_of_numbers];

def one_factor(n):
    i = 0
    factors = []
    m = np.ceil(np.sqrt(float(n)));
    while (i < give_up_threshold) and (early_primes[i] <= m):
        if n % early_primes[i]:
            i += 1
        else:
            return early_primes[i];
    
    return None;

def are_there_probably_primes(list_of_numbers):
    for x in list_of_numbers:
        if is_probable_prime(x) > 0:
            return True;
    return False;


def is_probable_prime(n, k = 9):
    if n < 6:
        return [False, False, True, True, False, True][n]
    elif n & 1 == 0:
        return False
    else:
        s, d = 0, n - 1
        while d & 1 == 0:
            s, d = s + 1, d >> 1
        for a in random.sample(range(2, min(n - 2, 10000000)), min(n - 4, k)):
            x = pow(a, d, n)
            if x != 1 and x + 1 != n:
                for r in range(1, s):
                    x = pow(x, 2, n)
                    if x == 1:
                        return False
                    elif x == n - 1:
                        a = 0
                        break
                if a:
                    return False
        return True

    
def jamCoin(N,J):
    init_num = 2**(N-1);
    init_J = 0;
    output = "";
    while(init_J < J):
        if init_num % 2:
            jamString = bin(init_num)[2:];
            jamArray = get_result(jamString);
            if not are_there_probably_primes(jamArray):
                factor_results = get_factors(jamArray);
                if None not in factor_results:
                    output = output + jamString + " " + " ".join([str(x) for x in get_factors(jamArray)]) + "\n";
                    init_J+=1;
            
        init_num+=1;
    return output;

def WriteResult(outputs):
    fh = open("output.out", "w")
    fh.write("Case #1:\n");
    fh.write(outputs);
    fh.close()

    


# In[163]:

#jamCoin(32,500)

WriteResult(jamCoin(32,500))
#init_num = 2**(32-1)


# In[ ]:



