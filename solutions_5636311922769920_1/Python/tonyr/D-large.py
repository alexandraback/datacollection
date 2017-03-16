
# coding: utf-8

# In[38]:

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
#f = open("D-small-attempt0.in", "r");
f = open("D-large.in", "r");


# In[39]:

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


# In[40]:

case_i = 1;
outputs = [];
for input_ in input_x:
    [K,C,S] = input_;
    if K == 1:
        print("Case #" + str(case_i) + ": 1");
    else:
        if C == 1:
            if S < K:
                print("Case #" + str(case_i) + ": IMPOSSIBLE");
                outputs.append("Case #" + str(case_i) + ": IMPOSSIBLE");
            else:
                outputs.append("Case #" + str(case_i)+": " + " ".join([str(x) for x in list(range(1,K+1))]));
                print("Case #" + str(case_i)+": " + " ".join([str(x) for x in list(range(1,K+1))]));
        if C > 1:
            if S < K-1:
                outputs.append("Case #" + str(case_i) + ": IMPOSSIBLE");
                print("Case #" + str(case_i) + ": IMPOSSIBLE");
            else:
                outputs.append("Case #" + str(case_i)+": " + " ".join([str(x) for x in list(range(2,K+1))]));
                print("Case #" + str(case_i)+": " + " ".join([str(x) for x in list(range(2,K+1))]));

    
    case_i +=1;


# In[41]:

def WriteResult(outputs):
    fh = open("output.out", "w")
    fh.write(outputs);
    fh.close()


# In[43]:

WriteResult(outputs)


# In[ ]:



