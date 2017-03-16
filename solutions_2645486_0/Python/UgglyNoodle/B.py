# Justin Ghan <justin.ghan@gmail.com>

# A is initial energy
def max_gain(A, E, R, v):
    if len(v) == 1:
        return v[0] * A
    
    min_a = max(A - E + R, 0)
    max_a = A
    a_list = range(min_a, max_a + 1)
    gain_list = []
    for i in range(len(a_list)):
        a = a_list[i]
        gain_list.append(v[0] * a + max_gain(A - a + R, E, R, v[1:]))
    return max(gain_list)

f_in = open('B-small-attempt0.in', 'r')
f_out = open('B-small-attempt0.out', 'w')

num_cases = int(f_in.readline().strip())

for idx_case in range(num_cases):
    E_R_N_list = f_in.readline().strip().split()
    E = int(E_R_N_list[0])
    R = int(E_R_N_list[1])
    N = int(E_R_N_list[2])
    v = [int(s) for s in f_in.readline().strip().split()]
    
    if R > E:
        gain = E * sum(v)
        f_out.write('Case #{}: {}\n'.format(idx_case+1, gain))
    else:
        f_out.write('Case #{}: {}\n'.format(idx_case+1, max_gain(E, E, R, v)))

f_in.close()
f_out.close()