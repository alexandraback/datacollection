import sys
from math import log2, floor, ceil
basename = "B-small-attempt0"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

for case in range(1, test_cases+1):
    A, B, K =[int(i) for i in input_file.readline().rstrip().split()]
    
    found = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                found += 1
    solution = found

    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

