
# coding: utf-8

# In[1]:

from collections import defaultdict


# In[60]:

fin = r'B-small-attempt2.in'
#fin = r'A-small-attempt1.in'
#fin = r'A-large.in'
with open(fin, 'r') as f:
    inputs = f.readlines()
results = []

l = 1
for t in range(int(inputs[0])):
    soldiers = defaultdict(int)
    N = int(inputs[l])
    l += 1
    
    for row in inputs[l:l+2*N-1]:
        rs = row.split()
        assert(len(rs)==N)
        for s in row.split():
            soldiers[s] += 1
    
    l = l+2*N-1
    
    res = sorted([int(k) for k,v in soldiers.items() if v%2!=0])
    results.append(' '.join(map(str, res)))
    assert(len(res)==N)


# In[61]:

fout = fin.replace('.in','.out')

with open(fout, 'w') as f:
    for i, res in enumerate(results):
        f.write("Case #%d: %s\n" % (i+1, str(res)))


# In[ ]:



