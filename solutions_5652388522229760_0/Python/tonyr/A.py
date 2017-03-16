
# coding: utf-8

# In[29]:

from __future__ import division
import fileinput
import math
import subprocess
import time

f = open("A-small-attempt0.in", "r")
i=1

N = 0;
input_x = [];
for line in f:
    if i == 1:
        N = int(line.rstrip());
    else:
        input_x.append(int(line));
    i+=1
f.close()


# In[31]:


def findLarge(generator):
    current_sum = generator;
    big_set = set();
    if(generator == 0):
        return "INSOMNIA";
    while(len(big_set) < 10):
        big_set = big_set.union(set(str(current_sum)));
        if(len(big_set) == 10):
            return current_sum;
        
        current_sum +=generator;
        
def WriteResult(outputs):
    fh = open("output.out", "w")
    case_i = 1;
    for case in outputs:
        fh.write("Case #" + str(case_i) + ": " + str(case) + "\n");
        case_i += 1;
        
    fh.close()

    


# In[32]:

output_y = [findLarge(x) for x in input_x];


# In[33]:



WriteResult(output_y)


# In[ ]:



