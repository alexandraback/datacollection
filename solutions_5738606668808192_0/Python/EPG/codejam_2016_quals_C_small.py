
# coding: utf-8

# In[13]:

# imports


# In[14]:

basepath = '/home/epg/halde/codejam/'


# In[70]:

testset = 'C-small-attempt0'


# In[71]:

def is_prime_in_base(s, base):
    """Return True iff the string s representing a binary number
       is prime when intepreted as a number in the provided base"""
    n = int(s, base)
    return (n > 2 and n%2 != 0 and all([n%i != 0 for i in xrange(3, int(n**0.5)+1, 2)]))
    
def is_not_prime(s):
    """Return True iff the string s representing a binary number
       is not a prime when interpreted as a number in any base from
       2 to 10 (inclusive)"""
    for base in xrange(2,11):
        if is_prime_in_base(s, base):
            return False
    return True


# In[72]:

def get_divisor(s, base):
    """Return the first non-trivial divisor of the string s 
       representing a binary number and intepreted as a number in 
       the provided base"""
    n = int(s, base)
    for i in xrange(2, int(n**0.5)+1):
        if n%i == 0:
            return i
    return None # should not happen
    
def get_divisors(s):
    """Return a list of each first non-trivial divisor of the string 
       s representing a binary number and intepreted as a number for 
       all bases from 2 to 10 (inclusive)"""
    return ' '.join([str(get_divisor(s, base)) for base in xrange(2,11)])


# In[73]:

def do_solve(N, J):
    sol = ''
    num_output = 0
    cur_number = 2**(N-1) + 1 # decimal
    
    while num_output < J:
        s = bin(cur_number)[2:] # bin() prepends '0b'
        if is_not_prime(s):
            # solution found
            sol += s + ' ' + get_divisors(s) + '\n'
            num_output += 1
        cur_number += 2        
    
    return sol


# In[ ]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        N, J = tuple(map(int, fin.readline().rstrip('\r\n').split(' ')))
        sol = do_solve(N, J)
        sol_string = 'Case #{}:'.format(i+1)
        sol_string += '\n'
        sol_string += sol
        
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:



