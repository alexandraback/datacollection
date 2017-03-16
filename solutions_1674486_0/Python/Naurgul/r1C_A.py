# IMPORTS
from sympy import Matrix

# FUNCTION DEFINITIONS GO HERE:


# MAIN PROGRAMME STARTS HERE:

num_cases = int(raw_input())

for case in range(num_cases):
    num_c = int(raw_input())
    for c in range(num_c):
        line = [0]*num_c
        data = map(lambda x: int(x), raw_input().split())
        for i in data[1:len(data)]:
            line[i-1] = 1
        if c==0:
            matrix = Matrix([line])
        else:
            matrix = matrix.col_join(Matrix([line]))
    matrix_power = matrix 
    matrix_sum = matrix
    for c in range(num_c-1): 
        matrix_power = matrix_power * matrix
        matrix_sum = matrix_sum + matrix_power         
        max_matrix = max(matrix_power)
        if max_matrix == 0 or max_matrix >= 2:
           break
    if max(matrix_sum) >=2:
        y = "Yes"
    else:
        y  = "No"
    print "Case #{0}: {1}".format(case+1, y)