
# coding: utf-8

# In[10]:

def rank_file(mat):
    n = len(mat);
    cnt = [0] * 2501;
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            cnt[mat[i][j]] += 1;
    out = [];
    for i in range(2501):
        if cnt[i] % 2 != 0:
            out.append(i);
    return(out);

fin_name = 'B-large.in';
fout_name = 'B-large.out';
fout = open(fout_name, 'w');
with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        mat = [];
        N = int(next(fin));
        for n in range(2*N-1):
            line = next(fin);
            mat.append(list(map(int, line.strip().split())));
        out = list(map(str, sorted(rank_file(mat))));
        line_out = 'Case #{0}: {1}\n'.format(str(case), ' '.join(out));
        fout.write(line_out);
fout.close();

            
    


# In[ ]:



