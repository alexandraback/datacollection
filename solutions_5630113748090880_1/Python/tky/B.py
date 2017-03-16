# Google code jam
import numpy as np


alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# read number of cases from stdin    
T = int(input()) 

for j in range(1,T+1):

    N = int(input()) # grid size NxN

    # read inputs into numpy array (N columns, 2N-1 rows)
    a = np.zeros((2*N-1,N))
    for i in range(0,2*N-1):
        a[i,:] = np.fromstring(input(), dtype=int, sep=' ')

    # find occurences of heights up to max -- unpaired heights
    # belong to missing row/column (max length is 2501)
    occ = np.bincount(np.array(np.resize(a,a.size),dtype=int))
    missing = np.zeros(N)
    cnt = 0
    for i in range(0,occ.size):
        if occ[i]%2 == 1:
            missing[cnt] = i
            cnt += 1
    # output is automatically ordered small to large            

    # if this is not true, the input ws not as expected
    assert cnt == N

    # write out to string
    outstr = "Case #{}: {}".format(j,int(missing[0]))
    if N > 1:
        for i in range(1,N):
            outstr += " {}".format(int(missing[i]))
        
    print(outstr)
