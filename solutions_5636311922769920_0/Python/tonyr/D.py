
# coding: utf-8

# In[16]:

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
f = open("D-small-attempt0.in", "r");


# In[17]:

i=1
N = 0;
input_x = [];
for line in f:
    if i == 1:
        N = int(line.rstrip());
    else:
        input_x.append([int(x) for x in line.split()]);
    i+=1
f.close()


# In[18]:

case_i = 1;
for input_ in input_x:
    [K,C,S] = input_;
    check_points = [x*(K**(C-1))+1 for x in list(range(K))]
    print("Case #" + str(case_i)+": " + " ".join([str(x) for x in check_points]));
    case_i +=1;


# In[19]:

def WriteResult(outputs):
    fh = open("output.out", "w")
    fh.write("Case #1:\n");
    fh.write(outputs);
    fh.close()


# In[ ]:



