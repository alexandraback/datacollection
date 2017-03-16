
# coding: utf-8

# In[1]:

# imports
import numpy as np # http://www.numpy.org/
import math # https://docs.python.org/2/library/math.html
import itertools as it # https://docs.python.org/2/library/itertools.html


# In[2]:

basepath = '/home/epg/halde/codejam/2016/1B/'


# In[28]:

testset = 'C-small-attempt0'


# In[29]:

def do_solve(s):
    fw = set()
    sw = set()
    
    for l in s:
        w1 = l.split(' ')[0]
        w2 = l.split(' ')[1]
        
        fw.add(w1)
        sw.add(w2)
    
    c = 0
    for p in it.product(fw, sw):
        if (p[0] + ' ' + p[1]) in set(s):
            c += 1
    
    res = c - max(len(fw), len(sw))
    
    return res


# In[30]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        N = int(fin.readline().rstrip('\r\n'))
        s = []
        for j in xrange(N):
            s.append(fin.readline().rstrip('\r\n'))

        sol = do_solve(s)

        sol_string = 'Case #{}: {}'.format(i+1, sol)
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:




# In[ ]:



