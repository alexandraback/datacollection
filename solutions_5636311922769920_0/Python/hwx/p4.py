
# coding: utf-8

# In[14]:

dset = r'p4\D-small-attempt0.in'
with open(dset, 'r') as f:
    inputs = f.readlines()

results = []
for line in inputs[1:]:
    K, C, S = map(int, line.split())
    
    s_req = (K + C - 1)//C
    
    if s_req > S:
        results.append(["IMPOSSIBLE"])
        continue
    
    k = K
    positions = []
    while k > 0:
        digs = [max(0, a) for a in range(k-C, k)]
        
        pos = sum([digs[i] * (K**i) for i in range(C)])+1
        positions.append(pos)
        
        k -= C
    results.append(positions)


# In[15]:

sol = r'p4\out'

with open(sol, 'w') as f:
    for i, res in enumerate(results):
        f.write('Case #%d: %s\n' % (i+1, ' '.join(map(str, res))))

