
# coding: utf-8

# In[89]:

# imports
from math import ceil # https://docs.python.org/2/library/math.html
from itertools import izip_longest # https://docs.python.org/2/library/itertools.html


# In[90]:

basepath = '/home/epg/halde/codejam/'


# In[91]:

testset = 'D-large'


# In[92]:

# source: https://docs.python.org/2/library/itertools.html#recipes
def grouper(iterable, n, fillvalue=None):
    "Collect data into fixed-length chunks or blocks"
    # grouper('ABCDEFG', 3, 'x') --> ABC DEF Gxx
    args = [iter(iterable)] * n
    return izip_longest(fillvalue=fillvalue, *args)


# In[93]:

def get_index(K, C, g):
    """g describes a path of children to take (index from 0). Returns the 
    resulting character's index in the leaf-level (output) string.
    len(g) must be at least C."""
    res = 0
    for i in xrange(C):
        res += g[i] * (K**(C-(i+1)))
    return res


# In[94]:

def do_solve(K, C, S):
    if S < ceil(float(K)/C):
        return 'IMPOSSIBLE'
    outvals = []
    for g in grouper(xrange(K), C, 0):
        o = get_index(K, C, g)# index from 0
        outvals.append(o + 1) # index from 1 for output
    return ' '.join([str(o) for o in outvals])


# In[95]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        K, C, S = tuple(map(int, fin.readline().rstrip('\r\n').split(' ')))
        
        sol = do_solve(K, C, S)
        
        sol_string = 'Case #{}: {}'.format(i+1, sol)
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:




# In[ ]:



