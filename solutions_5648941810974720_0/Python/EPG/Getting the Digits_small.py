
# coding: utf-8

# In[23]:

# imports
import numpy as np # http://www.numpy.org/
import math # https://docs.python.org/2/library/math.html
import itertools as it # https://docs.python.org/2/library/itertools.html
from collections import Counter # https://docs.python.org/2/library/collections.html


# In[24]:

basepath = '/home/epg/halde/codejam/2016/1B/'


# In[28]:

testset = 'A-small-attempt0'


# In[29]:

def do_solve(S):
    occ = Counter()
    
    # characters which occur in only one of the words and only once
    occ[0] = S.count('Z')
    occ[2] = S.count('W')
    occ[4] = S.count('U')
    occ[6] = S.count('X')
    occ[8] = S.count('G')
    # characters which occur in only two of the words and only once each
    occ[5] = S.count('F') - occ[4]
    occ[7] = S.count('S') - occ[6]
    occ[3] = S.count('H') - occ[8]
    # remaining chars
    occ[1] = S.count('O') - occ[0] - occ[2] - occ[4] # one O in each of those words
    occ[9] = S.count('I') - occ[5] - occ[6] - occ[8] # one I in each of those words
    
    res = ""
    for i in xrange(10):
        res += str(i)*occ[i]
    
    return res;


# In[30]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        S = fin.readline().rstrip('\r\n')
        
        sol = do_solve(S)
        
        sol_string = 'Case #{}: {}'.format(i+1, sol)
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:



