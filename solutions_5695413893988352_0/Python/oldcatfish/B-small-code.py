
# coding: utf-8

# In[17]:

def get_res(C, J):
    n = len(C);
    out_c = [0] * n;
    out_j = [0] * n;
    
    c_gt_j = -1;
    indx = 0;
    while indx < n:
        c = C[indx];
        j = J[indx];
        if c == '?' and j == '?':
            out_c[indx] = 0;
            out_j[indx] = 0;
            indx += 1;
            continue;
            
        if c == '?' and j != '?':
            out_c[indx] = int(j);
            out_j[indx] = int(j);
            indx += 1;
            continue;
        
        if c != '?' and j == '?':
            out_c[indx] = int(c);
            out_j[indx] = int(c);
            indx += 1;
            continue;
        
        if c == j:
            out_c[indx] = int(c);
            out_j[indx] = int(j);
            indx += 1;
            continue;
        
        if int(c) > int(j):
            out_c[indx] = int(c);
            out_j[indx] = int(j);
            c_gt_j = 1;
        else:
            out_c[indx] = int(c);
            out_j[indx] = int(j);
            c_gt_j = 0;
        indx += 1;
        break;
    
    
    if c_gt_j == 1:
        while indx < n:
            out_c[indx] = 0 if C[indx] == '?' else int(C[indx]);
            out_j[indx] = 9 if J[indx] == '?' else int(J[indx]);
            indx += 1;
    
    if c_gt_j == 0:
        while indx < n:
            out_c[indx] = 9 if C[indx] == '?' else int(C[indx]);
            out_j[indx] = 0 if J[indx] == '?' else int(J[indx]);
            indx += 1;
    
    out_c = ''.join(map(str, out_c));
    out_j = ''.join(map(str, out_j));
    
    return((out_c, out_j))

def is_match(num, s):
    n = len(s);
    c = str(num).zfill(n);
    for i in range(n):
        if s[i] != '?' and s[i] != c[i]:
            return(False);
    return(True);
    
def get_res_2(C, J):
    n = len(C);
    min_diff = float('inf');
    c_min = -1;
    j_min = -1;
    for c in range(10**n):
        if not is_match(c, C):
            continue;
        for j in range(10**n):
            if not is_match(j, J):
                continue;
            diff = abs(j - c);
            if diff < min_diff:
                c_min = c;
                j_min = j;
                min_diff = diff;
            
    return((str(c_min).zfill(n), str(j_min).zfill(n)));
                
            
        
    
            
fin_name = 'B-small-attempt0.in';
fout_name = 'B-small-attempt0.out';
fout = open(fout_name, 'w');

with open(fin_name) as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        C, J = next(fin).strip().split();
        out_c, out_j = get_res_2(C, J);
        line = "Case #{0}: {1} {2}\n".format(str(case), out_c, out_j);
        fout.write(line);
fout.close()        

        

