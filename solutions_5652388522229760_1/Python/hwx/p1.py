
# coding: utf-8

# In[11]:

din = r'p1\samp.in'
din = r'p1\A-small-attempt0.in'
#din = r'p1\B-large.in'
with open(din, 'r') as f:
    inputs = f.readlines()
    
results = []
all_digits = set(map(str, range(10)))

for line in inputs[1:]:
    N = int(line)
    if N == 0:
        results.append("INSOMNIA")
        continue
    dig_set = set()
    i = 1
    while True:
        dig_set = dig_set.union(set(str(i*N)))
        if dig_set == all_digits:
            break
        i += 1
    results.append(i*N)


# In[12]:

dout = r'p1\out'

with open(dout, 'w') as f:
    for i, res in enumerate(results):
        f.write("Case #%d: %s\n" % (i+1, str(res)))


# In[ ]:



