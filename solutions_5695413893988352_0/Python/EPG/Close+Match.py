
# coding: utf-8

# In[17]:

# imports
import numpy as np # http://www.numpy.org/
import math # https://docs.python.org/2/library/math.html
import itertools as it # https://docs.python.org/2/library/itertools.html


# In[18]:

basepath = '/home/epg/halde/codejam/2016/1B/'


# In[22]:

testset = 'B-small-attempt1'


# In[23]:

def do_solve(C, J):
    nodesC = []
    nodesJ = []
    nodesC.append(C)
    nodesJ.append(J)
    
    finNodesC = []
    finNodesJ = []
    
    while nodesC:
        node = nodesC.pop(0)
        i = node.find('?')
        if i == -1:
            finNodesC.append(node)
            continue
        else:
            for j in xrange(10):
                nodesC.append(node[0:i] + str(j)+ node[i+1:])
                
    while nodesJ:
        node = nodesJ.pop(0)
        i = node.find('?')
        if i == -1:
            finNodesJ.append(node)
            continue
        else:
            for j in xrange(10):
                nodesJ.append(node[0:i] + str(j)+ node[i+1:])
        
    minDiff = 1e100
    minC = None
    minJ = None
    for p in it.product(finNodesC, finNodesJ):
        diff = abs(int(p[0]) - int(p[1]))
        if diff < minDiff:
            minDiff = diff
            minC = p[0]
            minJ = p[1]
        elif diff == minDiff:
            if int(p[0]) < int(minC):
                minC = p[0]
                minJ = p[1]                
            if int(p[0]) == int(minC) and int(p[1]) < int(minJ):
                minC = p[0]
                minJ = p[1]                
                
    return minC + " " + minJ


# In[24]:

with open(basepath + testset + '.in') as fin, open(basepath + testset + '.out', 'w') as fout:
    T = int(fin.readline().rstrip('\r\n'))
    for i in xrange(T):
        # N, J = tuple(map(int, fin.readline().rstrip('\r\n').split(' ')))
        C, J = tuple(fin.readline().rstrip('\r\n').split(' '))
        
        sol = do_solve(C, J)
        
        sol_string = 'Case #{}: {}'.format(i+1, sol)
        fout.write(sol_string + '\n')
        print sol_string


# In[ ]:



