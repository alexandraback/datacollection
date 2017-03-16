
# coding: utf-8

# In[67]:

from collections import Counter
import numpy as np
def get_number(s):
    codes = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
    a = set();
    for word in codes:
        a |= set(word)
    all_letter = sorted(a);
    A = [];
    for i in range(len(codes)):
        tmp = [];
        cnt = Counter(codes[i]);
        for c in all_letter:
            tmp.append(cnt[c]);
        A.append(tmp);
    A = np.matrix(A).transpose();
    cnt_s = Counter(s);
    for i in range(len(codes)):
        tmp = [];
        for c in all_letter:
            tmp.append(cnt_s[c]);
    b = np.matrix(tmp).transpose();

    x = np.linalg.pinv(A) * b;

    x = [int(c.round()) for c in x];

    out = [];
    for i in range(10):
        out = out + [i] * x[i];
    out = ''.join(map(str, out));
    return(out);

fin_name = 'A-large.in';
fout_name = 'A-large.out';
fout = open(fout_name, 'w');

with open(fin_name) as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        s = next(fin).strip();
        out = get_number(s);
        line = "Case #{0}: {1}\n".format(str(case), out);
        fout.write(line);
fout.close()


# In[ ]:



