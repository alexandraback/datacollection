
# coding: utf-8

# In[13]:

# imports


# In[14]:

basepath = '/home/epg/halde/codejam/'


# In[15]:

testset = 'D-small-attempt0'


# In[16]:

def do_solve(K, C, S):
    return ' '.join([str(i+1) for i in xrange(K)])


# In[17]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        K, C, S = tuple(map(int, fin.readline().rstrip('\r\n').split(' ')))
        
        sol = do_solve(K, C, S)
        
        sol_string = 'Case #{}: {}'.format(i+1, sol)
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:



