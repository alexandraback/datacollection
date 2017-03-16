
# coding: utf-8

# In[4]:

def pancake(s):
    n = len(s);
    if n == 0:
        return(0);
    cnt = 0;
    for i in range(0, n-1):
        if s[i] == '+' and s[i+1] == '-':
            cnt += 2;
    if s[0] == '-':
        cnt += 1;
    return(cnt);

fin_name = 'B-small-attempt0.in';
fout_name = 'B-small-attempt0.out';

fout = open(fout_name, 'w');
with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        s = next(fin);
        cnt = pancake(s);
        fout.write("Case #{0}: {1}\n".format(str(case), str(cnt)));
        
fout.close();


# In[ ]:



