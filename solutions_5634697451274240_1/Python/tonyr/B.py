
# coding: utf-8

# In[119]:

from __future__ import division
import fileinput
import math
import subprocess
import time

f = open("B-large.in", "r");
#f = open("B-small-attempt1.in", "r");
#f = open("test_input.in", "r");
i=1

N = 0;
input_x = [];
for line in f:
    if i == 1:
        N = int(line.rstrip());
    else:
        input_x.append([1 if z == "+" else 0 for z in list(line.rstrip())]);
    i+=1
    
f.close()


# In[120]:

input_x


# In[121]:


        
def flippingPancakesSuperFast(stack_):
    
    flips = 0;
    if len(stack_) == 1:
        if stack_[0] == 0:
            return 1;
        return 0;
    
    for i in range(len(stack_)-1):
        if(stack_[i] != stack_[i+1]):
            flips +=1;
        if (i == len(stack_) - 2) and stack_[i+1] == 0:
            flips +=1;
    
    return flips;

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

    


# In[122]:

output_y = [flippingPancakesSuperFast(x) for x in input_x];


# In[123]:



WriteResult(output_y)


# In[ ]:



