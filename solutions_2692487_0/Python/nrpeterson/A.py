import sys

basename = "A-small-attempt1"

input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

def solve(A, motes):
    if A == 1:
        return len(motes)
    else:
        while len(motes) > 0 and motes[0] < A:
            A += motes[0]
            motes = motes[1:]
        if len(motes) == 0:
            return 0
        newA = A
        newmotes = motes[:]
        to_add = 0
        while newA <= newmotes[0]:
            newA += newA - 1
            to_add += 1

        cleared = 0
        while len(newmotes) > 0 and newA > newmotes[0]:
            newA += newmotes[0]
            newmotes = newmotes[1:]
            cleared += 1

        if cleared >= to_add:
            return to_add + solve(newA, newmotes)
        else:
            return len(motes)

for case in range(1, test_cases+1):
    A, N = [int(c) for c in input_file.readline().rstrip().split()]
    motes = sorted([int(c) for c in input_file.readline().rstrip().split()])

    solution = solve(A, motes)

    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

