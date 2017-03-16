
# coding: utf-8

# In[7]:

fin_name = 'D-small-attempt0.in';
fout_name = 'D-small-attempt0.out';
fout = open(fout_name, 'w');
with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        K, C, S = map(int, next(fin).split(' '));
        line = 'Case #{0}: {1}\n'.format(str(case), ' '.join(map(str, range(1, S+1))));
        fout.write(line);
fout.close();
        


# In[ ]:



