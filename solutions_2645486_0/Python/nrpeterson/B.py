from math import ceil

basename = "B-small-attempt3"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

def solve(E, J, R, vals):
    if len(vals) == 1:
        return J * vals[0]
    elif E <= R:
        return E * sum(vals)
    else:
        return max(i*vals[0] + solve(E, min(J-i+R, E), R, vals[1:]) for i in range(J+1))

for case in range(1, test_cases+1):
    E, R, N = [int(c) for c in input_file.readline().rstrip().split()]
    vals = [int(c) for c in input_file.readline().rstrip().split()]
    
    solution = solve(E, E, R, vals)
    
    #print(solution)
    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

