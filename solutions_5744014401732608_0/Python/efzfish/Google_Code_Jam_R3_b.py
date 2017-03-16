
# coding: utf-8

# In[133]:

T = int(raw_input())
data = []

for k in range(T):
    row = map(int, raw_input().split(' '))
    data.append(row)


# In[6]:

import numpy as np


# In[122]:

def pro_b(B, M):
    if M == 0:
        return np.zeros((B,B))
    elif 2 ** (B-2) < M:
        return 'IMPOSSIBLE'
    else:
        matrix = np.zeros((B,B))
        for i in range(B-1):
            for j in range(i+1,B):
                matrix[i][j]=1
        k = 2**(B-2)-M
        for i in range(B-2):
            if bool(k & (2**i)):
                matrix[0][B-2-i]=0
        return matrix


# In[134]:

for i in range(T):
    ans = pro_b(data[i][0],data[i][1])
    if ans == 'IMPOSSIBLE':
        print 'Case #{}: IMPOSSIBLE'.format(i+1)
    else:
        print 'Case #{}: POSSIBLE'.format(i+1)
        for j in range(data[i][0]):
            print ''.join(map(str,map(int,ans[j])))


# In[ ]:



