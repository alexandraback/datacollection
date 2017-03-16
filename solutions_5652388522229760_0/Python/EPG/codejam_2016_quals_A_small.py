
# coding: utf-8

# In[1]:

# imports
import numpy as np # http://www.numpy.org/


# In[2]:

basepath = '/home/epg/halde/codejam/'


# In[7]:

testset = 'A-small-attempt0'


# In[8]:

def get_digits(N):
    return [int(c) for c in list(str(N))]


# In[9]:

def do_solve(N):
    cur_N = N
    seen_digits = np.zeros((10), dtype=bool)
    seen_numbers = set()
    
    while cur_N not in seen_numbers:
        for digit in get_digits(cur_N):
            seen_digits[digit] = True
        if np.all(seen_digits):
            return cur_N
        seen_numbers.add(cur_N)
        cur_N += N
        
    return 'INSOMNIA'    


# In[10]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        N = int(fin.readline().rstrip('\r\n'))
        sol = do_solve(N)
        sol_string = 'Case #{}: {}'.format(i+1, sol)
        
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:



