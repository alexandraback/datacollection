#!/usr/bin/env/python

input_file = 'password-small.dat'

with open (input_file, 'r') as data_file:
    N_tests = int(data_file.readline())
    
    for i in range(0, N_tests):
        (A, B) = map(int, data_file.readline().split(' '))
        p_list = map(float, data_file.readline().split(' '))
        
        # Convert p_list to partial products
        pp_list = []
        tmp = 1
        for j in range(0, len(p_list)):
            tmp = tmp * p_list[j]
            pp_list.append(tmp)
        
        # First test case: just hit enter
        best_case = (B+2)
        
        # Second test case: maximum number of backspaces
        if (best_case > (A+B+1)):
            best_case = A+B+1
        
        # Now test various # of backspaces
        for Nb in range(0, A):
            exp_ks = (B-A+1+2*Nb) * pp_list[A-Nb-1]
            exp_ks = exp_ks + (2*B - A + 2*Nb + 2) * (1 - pp_list[A-Nb-1])
            if (exp_ks < best_case):
                best_case = exp_ks
        
        case_str = "Case #{0:d}: {1:f}".format(i+1, best_case)
        print case_str

