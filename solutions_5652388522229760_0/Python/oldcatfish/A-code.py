
# coding: utf-8

# In[22]:

def count_sheep(N):
    if N == 0:
        return('INSOMNIA');
    d = set();
    i = 0;
    while len(d) < 10:
        i += 1;
        val = i * N;
        d = d.union(set(str(val)));
        
    return(str(val))


# get output
fin_name = 'A-small-attempt0.in';
fout_name = 'A-small-attempt0.out';

fout = open(fout_name, 'w');
with open(fin_name, 'rb') as fin:
    T = int(next(fin));
    for case in range(T):
        N = int(next(fin));
        out = count_sheep(N);
        fout.write('Case #{0}: {1}\n'.format(str(case+1), out));
fout.close();

