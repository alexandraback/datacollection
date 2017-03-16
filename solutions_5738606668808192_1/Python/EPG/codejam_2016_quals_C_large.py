
# coding: utf-8

# In[62]:

# imports


# In[63]:

basepath = '/home/epg/halde/codejam/'


# In[64]:

testset = 'C-large'


# In[65]:

known_divisors = {} # key1: binary string, key2: base (int)

def is_maybe_prime_in_base(s, base, max_n = None):
    """Return True iff the string s representing a binary number
       is maybe prime when intepreted as a number in the provided base.
       Additionally, stores a know divisor for non-prime numbers.
       Here, only a certain number of divisors up to the provided 
       max_n or all possible ones are tested."""
    n = int(s, base)
    if not max_n:
        max_n = int(n**0.5)+1
    
    if n == 1:
        return False
    elif n == 2 or n == 3:
        return True
    elif n%2 == 0:
        if s not in known_divisors:
            known_divisors[s] = {}
        known_divisors[s][base] = 2
        return False
    
    for i in xrange(3, max_n, 2):
        if n%i == 0:
            if s not in known_divisors:
                known_divisors[s] = {}
            known_divisors[s][base] = i
            return False
    return True
    
def is_not_prime(s, max_n = None):
    """Return True iff the string s representing a binary number
       is not a prime when interpreted as a number in any base from
       2 to 10 (inclusive)"""
    for base in xrange(2,11):
        if is_maybe_prime_in_base(s, base, max_n):
            return False
    return True


# In[66]:

def get_divisor(s, base):
    """Return the first non-trivial divisor of the string s 
       representing a binary number and intepreted as a number in 
       the provided base. Must be already inserted into 
       known_divisors by is_prime_in_base."""
    return known_divisors[s][base]
    
def get_divisors(s):
    """Return a list of each first non-trivial divisor of the string 
       s representing a binary number and intepreted as a number for 
       all bases from 2 to 10 (inclusive)"""
    return ' '.join([str(get_divisor(s, base)) for base in xrange(2,11)])


# In[67]:

def do_solve(N, J):
    num_output = 0
    cur_number = 2**(N-1) + 1 # decimal
    found_solutions = set()
    
    # fast check using only small divisors
    while num_output < J and cur_number < 2**N:
        s = bin(cur_number)[2:] # bin() prepends '0b'
        if is_not_prime(s, 12):
            # solution found
            found_solutions.add(s)
            yield s + ' ' + get_divisors(s)
            num_output += 1
        cur_number += 2
    
    # slow check for new ones using all possible divisors
    while num_output < J and cur_number < 2**N:
        s = bin(cur_number)[2:] # bin() prepends '0b'
        if s not in found_solutions and is_not_prime(s):
            # solution found
            found_solutions.add(s)
            yield s + ' ' + get_divisors(s)
            num_output += 1
        cur_number += 2


# In[68]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        N, J = tuple(map(int, fin.readline().rstrip('\r\n').split(' ')))
        
        header = 'Case #{}:'.format(i+1)
        fout.write(header + '\n')
        print header
        
        for sol in do_solve(N, J):
            fout.write(sol + '\n')
            print sol


# In[ ]:



