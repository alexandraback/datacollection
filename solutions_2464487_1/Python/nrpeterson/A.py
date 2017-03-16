from math import floor, sqrt
import sys

basename = "A-large"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

for case in range(1, test_cases+1):
    r, t = [int(c) for c in input_file.readline().rstrip().split()]

    sol1 = floor( (1 - 2*r + sqrt(1-4*r+4*(r**2)+8*t)) / 4)
    sol2 = floor( (1 - 2*r - sqrt(1-4*r+4*(r**2)+8*t)) / 4)
    sol = max(sol1, sol2)
    if 2*r*sol - 3*sol + 2*sol*(sol+1) > t:
        sol -= 1
    solution = str(sol)
    print(solution)
    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

