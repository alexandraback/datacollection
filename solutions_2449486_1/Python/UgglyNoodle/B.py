f_in = open('B-large.in', 'r')
f_out = open('B-large.out', 'w')

num_cases = int(f_in.readline().strip())

for idx_case in range(num_cases):
    N_M_list = f_in.readline().strip().split()
    N = int(N_M_list[0])
    M = int(N_M_list[1])
    
    rows = []
    for i in range(N):
        row = [int(s) for s in f_in.readline().strip().split()]
        rows.append(row)
    
    possible = True
    
    for i in range(N):
        for j in range(M):
            row_check = any([h > rows[i][j] for h in rows[i]])
            column_check = any([h > rows[i][j] for h in [rows[k][j] for k in range(N)]])
            if row_check and column_check:
                possible = False
    
    result = 'YES' if possible else 'NO'
    
    f_out.write('Case #{}: {}\n'.format(idx_case+1, result))

f_in.close()
f_out.close()