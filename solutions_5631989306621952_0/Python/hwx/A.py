
# coding: utf-8

# In[12]:

#fin = r'A-samp.in'
fin = r'A-small-attempt0.in'
#fin = r'A-large.in'
with open(fin, 'r') as f:
    inputs = f.readlines()
results = []

for line in inputs[1:]:
    res = []
    for c in line.strip():
        if res == []:
            res.append(c)
        if ord(c) >= ord(res[0]):
            res = [c] + res
        else:
            res.append(c)
    results.append(''.join(res))


# In[13]:

fout = fin.replace('.in','.out')

with open(fout, 'w') as f:
    for i, res in enumerate(results):
        f.write("Case #%d: %s\n" % (i+1, str(res)))


# In[ ]:



