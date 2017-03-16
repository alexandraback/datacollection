
# coding: utf-8

# In[1]:

# Template


# In[42]:

get_ipython().magic(u'matplotlib inline')
import numpy as np
import matplotlib.pyplot as plt

from __future__ import division
import time, random, re, copy , pickle
from operator import itemgetter
from math import *


# In[ ]:




# In[ ]:

#reading file
f_name = 'B-small42.in'
f = open(f_name,'r')

N = int(f.readline())

L = []
for _ in range(N):
    print(_)
    #c = int(f.readline()) 
    tmp = f.readline()
    k,l,s = map(int, tmp.split(" "))
    keys = f.readline()[:-1] #map(f.readline().split())
    target = f.readline()[:-1]
    if is_possible(keys, target):
        L.append(re(s,target,k,keys))
    else:
        L.append(0)
        #print('nposiible')


# In[192]:

L


# In[177]:

max_banana(s,target)


# In[17]:

def max_overlap(t= 'target'):
    
    ll = len(t)
    for i in range(1,ll):
        if t[i:] == t[:-i]:
            return ll - i
    return 0
    


# In[48]:

def max_banana(s= 10,t= 'target'):
    
    lt = len(t)
    count = 0
    s = s - lt
    if s < 0:
        return 0
    else:
        count += 1
        count += int(s/(lt - max_overlap(t)))
        return count


# In[60]:

def is_possible(keys, t = 'target'):
    
    return set(np.unique([x for x in t])).issubset(set(np.unique([x for x in keys])))


# In[109]:

def compte(k, s, tab):
    
    if s == 0 :
        return tab
    
    else:

        if tab[-1]< k-1:
            tab[-1] += 1
            return tab
        else:
            return compte(k, s-1, tab[:-1]) + [0]
        


# In[188]:

def re(s,target,k,keys):
    tab = [0] * s
    res = 0
    max_bananas = max_banana(s,target)
    for i in range(np.power(k,s)):

        lettre = [keys[x] for x in tab]
        #print(lettre)

        bc = 0
        for index in range(len(lettre) - len(target) +1 ):
            #print(lettre[index:index + len(target)])
            if ''.join(lettre[index:index + len(target)]) == target:
                bc+= 1

        res += max_bananas - bc

        tab = compte(k,s, tab)

    return res/ (np.power(k,s))


# In[187]:

tab = [0] * s
res = 0
max_bananas = max_banana(s,target)
for i in range(np.power(k,s)):

    lettre = [keys[x] for x in tab]
    #print(lettre)

    bc = 0
    for index in range(len(lettre) - len(target) +1 ):
        #print(lettre[index:index + len(target)])
        if ''.join(lettre[index:index + len(target)]) == target:
            bc+= 1
    #print(bc)

    res += max_bananas - bc

    tab = compte(k,s, tab)

(res ) / (np.power(k,s))


# In[185]:

tab


# In[146]:

print(max_overlap('badaba'))
print(max_overlap('azerta'))

print(max_banana(4,'aa')) #ok
print(is_possible('azerdfaty','azeebrezazea'))


# In[ ]:




# In[49]:

a = set(range(4))


# In[46]:




# In[ ]:

#writing file

out = open('out_42.txt','w')
for i,(S,n,li) in enumerate(L):
    #print('Case #' + str(i+1) + ': ' + str(g(S,li)))
    out.write('Case #' + str(i+1) + ': ' + str(g(S,li)) + '\n')
    
out.close()


# In[ ]:



