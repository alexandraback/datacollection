
# coding: utf-8

# In[17]:

import numpy as np
from collections import Counter



# In[18]:

num = int(raw_input())
data = []

for i in range(num):
    data.append(raw_input())


# In[1]:

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


# In[16]:

def pro_a(x):
    c = Counter(x)
    ct = np.zeros(10)
    ct[0] = c['Z']
    ct[2] = c['W']
    ct[4] = c['U']
    ct[6] = c['X']
    ct[8] = c['G']
    for i in [0,2,4,6,8]:
        for j in numbers[i]:
            c[j] = c[j] - ct[i]
    ct[1] = c['O']
    ct[3] = c['T']
    ct[5] = c['F']
    ct[7] = c['S']
    for i in [1,3,5,7]:
        for j in numbers[i]:
            c[j] = c[j] - ct[i]
    ct[9] = c['I']
    return '0'*ct[0]+'1'*ct[1]+'2'*ct[2]+'3'*ct[3]+'4'*ct[4]+'5'*ct[5]+'6'*ct[6]+'7'*ct[7]+'8'*ct[8]+'9'*ct[9]


# In[19]:

for i in range(num):
    print 'Case #{}: {}'.format(i+1, pro_a(data[i]))


# In[ ]:



