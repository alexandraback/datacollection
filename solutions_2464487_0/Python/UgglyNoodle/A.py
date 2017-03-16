# Justin Ghan <justin.ghan@gmail.com>

import math

f_in = open('A-small-attempt0.in', 'r')
f_out = open('A-small-attempt0.out', 'w')

def fun(k, r):
    return k * (2 * (k + r) - 1) - t

def fun_prime(k, r):
    return 4 * k + 2 * r - 1

num_cases = int(f_in.readline().strip())

for idx_case in range(num_cases):
    r_t_list = f_in.readline().strip().split()
    r = int(r_t_list[0])
    t = int(r_t_list[1])
    
    s = 2 * r - 1
    d = s * s + 8 * t
    k_lim = (math.sqrt(d) - s) / 4
    k = int(math.floor(k_lim))
    
    while (fun(k, r) > 0 or fun(k + 1, r) <= 0):
        k_new = k - float(fun(k, r)) / float(fun_prime(k, r))
        k = int(math.floor(k_new))
    
    f_out.write('Case #{}: {}\n'.format(idx_case+1, k))

f_in.close()
f_out.close()