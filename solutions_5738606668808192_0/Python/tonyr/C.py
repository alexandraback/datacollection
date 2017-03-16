
# coding: utf-8

# In[39]:

from __future__ import division
import fileinput
import math
import subprocess
import time
import numpy as np;
import timeit;
#f = open("B-large.in", "r");
#f = open("B-small-attempt1.in", "r");
#f = open("test_input.in", "r");
from primesieve import *


# In[41]:

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
    i = 2
    factors = []
    m = np.ceil(np.sqrt(n));
    while i <= m:
        if n % i:
            i += 1
        else:
            return i;
        

def jamCoin(N,J):
    init_num = 2**(N-1);
    init_J = 0;
    output = "";
    while(init_J < J):
        if init_num % 2:
            jamString = bin(init_num)[2:];
            jamArray = get_result(jamString);
            if not are_there_primes(jamArray):
                output = output + jamString + " " + " ".join([str(x) for x in get_factors(jamArray)]) + "\n";
                init_J+=1;
            
        init_num+=1;
    return output;

def WriteResult(outputs):
    fh = open("output.out", "w")
    fh.write("Case #1:\n");
    fh.write(outputs);
    fh.close()

    


# In[42]:



WriteResult(jamCoin(16,50))


# In[ ]:



