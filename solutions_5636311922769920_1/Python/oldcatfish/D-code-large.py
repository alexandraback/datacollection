
# coding: utf-8

# In[36]:

def fractiles(K, C, S):
    if C == 1:
        if S < K:
            return(False);
        return(list(range(1, K+1)));
    out = [];
    start = 0;
    #max_val = K ** C;
    step = C * (K ** (C-1));
    for i in range(S):
        offset =  (i+1) * C;
        if offset >= K:
            val = start + K;
            out.append(val);
            return(out);
        val = start + offset;
        out.append(val);
        start += step;
        #print(val)
    return(False);

fin_name = 'D-large.in';
fout_name = 'D-large.out';
fout = open(fout_name, 'w');

with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case_id in range(1, T+1):
        K, C, S = map(int, next(fin).split(' '));
        out = fractiles(K, C, S);
        if not out:
            res_str = 'IMPOSSIBLE';
        else:
            res_str = ' '.join(map(str, out));
        line = "Case #{0}: {1}\n".format(str(case_id), res_str);
        fout.write(line);
fout.close();


# In[ ]:



