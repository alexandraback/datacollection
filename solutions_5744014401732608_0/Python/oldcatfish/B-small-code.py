
# coding: utf-8

# In[30]:

B = 5;
M = 4;
def fill_j(mat, j):
    # fill index mat[0][j]
    mat[0][j] = 1;
    for i in range(j, len(mat)):
        for j1 in range(i+1, len(mat)):
            mat[i][j1] = 1;

def get_res(B, M):
    mat = [[0 for j in range(B)] for i in range(B)];
    m_str = bin(M)[2:];
    if len(m_str) > B-1:
        return(False);
    while len(m_str) < B - 1:
        m_str = '0' + m_str;
    
    for j in range(B-1):
        if m_str[j] == '1':
            fill_j(mat, j);
    mat[0][0] = 0;
    return(mat)

fin_name = 'B-small-attempt1.in';
fout_name = 'B-small-attempt1.out';
fout = open(fout_name, 'w');
with open(fin_name) as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        B, M = list(map(int, next(fin).strip().split()));
        res = get_res(B, M);
        if not res:
            line = 'Case #{0}: IMPOSSIBLE\n'.format(str(case));
            fout.write(line);
            continue;
        line = 'Case #{0}: POSSIBLE\n'.format(str(case));
        fout.write(line);
        for i in range(B):
            line = '{0}\n'.format(''.join(map(str, res[i])));
            fout.write(line);
fout.close();


# In[ ]:



