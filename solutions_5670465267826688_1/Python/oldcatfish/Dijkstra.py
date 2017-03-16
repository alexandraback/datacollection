map_ijk = {'1':0, 'i':1, 'j':2, 'k':3};
TABLE_PROD = [[(1, '1'), (1, 'i'), (1, 'j'), (1, 'k')],
[(1, 'i'), (-1, '1'), (1, 'k'), (-1, 'j')],
[(1, 'j'), (-1, 'k'), (-1, '1'), (1, 'i')],
[(1, 'k'), (1, 'j'), (-1, 'i'), (-1, '1')]];


def prod_ijk(val1, val2):
    sign1 = val1[0];
    sign2 = val2[0];
    indx1 = map_ijk[val1[1]];
    indx2 = map_ijk[val2[1]];
    tmp = TABLE_PROD[indx1][indx2];
    return((sign1*sign2*tmp[0], tmp[1]));
    

# test 
#print(prod_ijk((-1, 'i'), (1, 'i')));

# find total product of s
def existPartition(L, X, s):
    total_s = (1, '1');
    for element in s:
        total_s = prod_ijk(total_s, (1, element));
    
    if X%4 == 0:
        total_lx = (1, '1');
    else:
        total_lx = total_s;
        for indx in range(X%4 - 1):
            total_lx = prod_ijk(total_lx, total_s);
    
    if total_lx[0] != -1 or total_lx[1] != '1':
        # return
        return(False);   
        
    
    if X < 4:
        s1 = s*X;
    else:
        s1 = s*4;
    
    # find left
    indx_i = -1;
    total_i = (1, '1');
    for element in s1:
        total_i = prod_ijk(total_i, (1, element));
        indx_i += 1;
        if total_i[0] == 1 and total_i[1] == 'i':
            break;
    
    if indx_i == len(s1):
        return(False);
    
    # find right
    indx_k = len(s1) -1;
    total_k = (1, '1');
    while indx_k >= 0:
        total_k = prod_ijk((1, s1[indx_k]), total_k);
        if total_k[0] == 1 and total_k[1] == 'k':
            break;
        indx_k -= 1;
    
    if indx_k == -1:
        return(False);
    
    tmp = len(s1) - indx_k + indx_i + 1;
    if tmp >= X * L:
        return(False);
    
    return(True);

## read file and output            
infile = open('C-large.in', 'r');
num_test = int(next(infile));

for indx_test in range(num_test):
    tmp = next(infile);
    tmp = tmp.split();
    L = int(tmp[0]);
    X = int(tmp[1]);
    s = next(infile);
    s = s.strip();
    print('Case #' + str(indx_test + 1) + ': ', end="");
 
    if existPartition(L, X, s):
        print('YES');
    else:
        print('NO');   


    
    
    
        