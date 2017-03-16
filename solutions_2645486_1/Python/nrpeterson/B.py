from math import ceil

basename = "B-large"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

def step(E, J, R, vals):
    if len(vals) == 1:
        return J 
    elif E <= R:
        return E 
    else:
        p = 0
        while p+1 < len(vals) and vals[p+1] <= vals[0]:
            p += 1
        if p == 0:
            USE = max(J - (E - R), 0)
        else:
            USE = min(J, p * R)
        return USE 

for case in range(1, test_cases+1):
    E, R, N = [int(c) for c in input_file.readline().rstrip().split()]
    vals = [int(c) for c in input_file.readline().rstrip().split()]
    
    steps = []
    J = E
    for i in range(len(vals)):
        s = step(E, J, R, vals[i:])
        steps.append(s)
        J = min(J-s+R, E)

    solution = sum(steps[i] * vals[i] for i in range(len(vals)))
    
    #print(solution)
    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

