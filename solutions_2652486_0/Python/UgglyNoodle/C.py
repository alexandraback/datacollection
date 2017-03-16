# Justin Ghan <justin.ghan@gmail.com>

f_in = open('C-small-1-attempt0.in', 'r')
f_out = open('C-small-1-attempt0.out', 'w')

def get_pow(P, q):
    pow_q = 0
    while (P % q == 0):
        P /= q
        pow_q += 1
    return pow_q

num_cases = int(f_in.readline().strip())

f_out.write('Case #1:\n')

R_N_M_K_list = f_in.readline().strip().split()
R = int(R_N_M_K_list[0])
N = int(R_N_M_K_list[1])
M = int(R_N_M_K_list[2])
K = int(R_N_M_K_list[3])

for idx_case in range(R): # FIXME range(R)
    P_list = [int(s) for s in f_in.readline().strip().split()]
    
    pow_2 = [get_pow(P, 2) for P in P_list]
    pow_3 = [get_pow(P, 3) for P in P_list]
    pow_5 = [get_pow(P, 5) for P in P_list]
    
    min_occ_3 = max(pow_3)
    min_occ_5 = max(pow_5)
    
    min_occ_4 = max(pow_2) / 2
    min_occ_2 = 1 if any(a % 2 == 1 for a in pow_2) else 0
    
    if min_occ_2 + min_occ_3 + min_occ_4 + min_occ_5 == N:
        alist = [2] * min_occ_2 + [3] * min_occ_3 + [4] * min_occ_4 + [5] * min_occ_5
    else:
        alist = [2] * N
    
    f_out.write('{}\n'.format(''.join([str(a) for a in alist])))

f_in.close()
f_out.close()