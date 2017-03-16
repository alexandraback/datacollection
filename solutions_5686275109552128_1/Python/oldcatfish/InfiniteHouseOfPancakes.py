'''
Ominous Ominov
'''
import numpy as np;
infile = open('B-large.in', 'r');
num_test = int(next(infile));
for indx_test in range(num_test):
    D = int(next(infile));
    P_text = next(infile);
    P = np.array([int(x) for x in P_text.split()]);
    P_max = max(P);
    time_min = P_max;
    
    for P_min in range(1, P_max):
        time_extra = sum((P - 1)//P_min);
        time_min = min(time_min, P_min + time_extra);
    print('Case #' + str(indx_test + 1) + ': ', end="");
    print(str(time_min));
    
