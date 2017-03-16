
# coding: utf-8

# In[6]:

din = r'p2\B-small-attempt0.in'

with open(din, 'r') as f:
    inputs = f.readlines()
    
results = []
for line in inputs[1:]:
    cur = '+'
    flip = 0
    for c in reversed(line.strip()):
        if cur != c:
            flip += 1
            cur = c
    results.append(flip)


# In[7]:

dout = r'p2\out'

with open(dout, 'w') as f:
    for i, res in enumerate(results):
        f.write("Case #%d: %d\n" % (i+1, res))


# In[ ]:



