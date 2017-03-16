
# coding: utf-8

# In[35]:

from collections import Counter
from itertools import chain, combinations


# In[32]:

def solve_1(table):
    firsts, seconds = map(set, zip(*table))
    return len(table) - max(len(firsts), len(seconds))


# In[29]:

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


# In[40]:

def solve(table):
    firsts, seconds = map(Counter, zip(*table))
    
    reals = set()
    maybes = set()
    # divide into reals and possible fakes:
    for item in table:
        first, second = item
        if firsts[first] == 1 or seconds[second] == 1:
            # must be real
            reals.add(item)
        else:
            maybes.add(item)
    
    highest = 0
    for fakes in powerset(maybes):
        fakes = set(fakes)
        myreals = (maybes - fakes) | reals
        if not myreals:
            continue
        firsts, seconds = map(Counter, zip(*myreals))
        for fake in fakes:
            first, second = fake
            if first in firsts and second in seconds:
                continue
            break
        else:
            highest = max(highest, len(fakes))
    
            
    return highest


# In[ ]:




# In[11]:

def solve_wrong(table, fakes=0):
    firsts, seconds = map(Counter, zip(*table))
    # if both first and second word are unoriginal, it may be fake
    for item in table[:]:
        first, second = item
        if firsts[first] > 1 and seconds[second] > 1:
            table.remove(item)
            return solve(table, fakes=fakes+1)
    return fakes


# In[ ]:

cases = int(input())

for case in range(1, 1+cases):
    n = int(input())
    table = [input().split() for _ in range(n)]
    table = [tuple(x) for x in table]
    answer = solve(table)
    print("Case #{}: {}".format(case, answer))

