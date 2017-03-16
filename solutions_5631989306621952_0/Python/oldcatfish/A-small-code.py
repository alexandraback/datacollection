
# coding: utf-8

# In[12]:

def last_word(s):
    cur = '';
    s = s.strip();
    for i in range(len(s)):
        if cur + s[i] > s[i] + cur:
            cur = cur + s[i];
        else:
            cur = s[i] + cur;
    return(cur)
    
fin_name = 'A-sample.in';
fout_name = 'A-sample.out';
fout = open(fout_name, 'w');

with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        s = next(fin);
        line = 'Case #{0}: {1}\n'.format(str(case), last_word(s));
        fout.write(line);
fout.close();

