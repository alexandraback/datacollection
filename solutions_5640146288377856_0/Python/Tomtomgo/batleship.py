
# coding: utf-8

# In[1]:

# Template


# In[2]:

get_ipython().magic(u'matplotlib inline')
import numpy as np
import matplotlib.pyplot as plt

from __future__ import division
import time, random, re, copy , pickle
from operator import itemgetter
from math import *


# In[ ]:




# In[12]:

#reading file
f_name = 'A-small-practice.in'
f = open(f_name,'r')

N = int(f.readline())

L = []
res = []
for _ in range(N):
    #c = int(f.readline()) 
    tmp = f.readline()
    R, C, W = map(int, tmp.split(" "))
    if C/W == int(C/W):
        bias = 1
    else:
        bias = 0
    L.append(int(C/W) * R + W - bias)


# In[7]:

R, C , W


# In[ ]:

#Pandas

vect = pd.read_csv(path + name_g , names = range(51), delimiter=" ", quoting=3)


# In[ ]:

res = int(C/W) * R + W


# In[ ]:




# In[11]:

#writing file

out = open('out_42.txt','w')
for i,(rr) in enumerate(L):
    #print('Case #' + str(i+1) + ': ' + str(g(S,li)))
    out.write('Case #' + str(i+1) + ': ' + str(rr) + '\n')
    
out.close()


# In[ ]:



