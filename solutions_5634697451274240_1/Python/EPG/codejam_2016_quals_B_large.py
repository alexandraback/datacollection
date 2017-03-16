
# coding: utf-8

# In[72]:

# imports
from string import maketrans # https://docs.python.org/2/library/string.html


# In[73]:

basepath = '/home/epg/halde/codejam/'


# In[74]:

testset = 'B-large'


# In[75]:

swapmap = maketrans('+-', '-+')
def do_flip(S, n):
    """Perform a flip of the first n items of S and return the result"""
    return S[0:n][::-1].translate(swapmap) + S[n:]


# In[76]:

def do_solve(S):
    # approach build sequence of '+' bottom up
    steps = 0
    
    while S.find('-') != -1:
        index_first_minus = S.find('-')
        index_last_minus = S.rfind('-')
        
        # create longest possible prefix of '-' with single flip
        # i.e., flip the current (maybe empty) prefix of '+'
        if index_first_minus > 0:
            S = do_flip(S, index_first_minus)
            steps += 1
        # flip part up to (including) last '-'
        S = do_flip(S, index_last_minus + 1)
        steps += 1
    
    return steps


# In[71]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        S = fin.readline().rstrip('\r\n')
        sol = do_solve(S)
        sol_string = 'Case #{}: {}'.format(i+1, sol)
        
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:



