import sys
from math import factorial

def binomial(n,r):
    return int(factorial(n) / (factorial(r) * factorial(n-r)))

basename = "B-large"


input_filename = basename + ".in"
output_filename = basename + ".out"

input_file = open(input_filename, 'r')
output_file = open(output_filename, 'w')

test_cases = int(input_file.readline().rstrip())

for case in range(1, test_cases+1):
    N, X, Y = [int(c) for c in input_file.readline().rstrip().split()]

    print("Case: " + str(case))
    print("N=" + str(N), "(X,Y)=" + str((X,Y)))

    if (X + Y) % 2 != 0:
        solution = 0
        print("Impossible position!")
    else:
        l = 0
        while N >= (l+1)*(2*(l+1)-1):
            l += 1
        print("Use " + str(l*(2*l-1)) + " diamonds to get " + str(l) + "layers.")
        if abs(X) + abs(Y) <= 2 * (l - 1):
            solution = 1
            print("We have already covered (X,Y).")
        elif abs(X) + abs(Y) > 2 * l or (X,Y) == (0,2*l):
            solution = 0
            print("(X,Y) is too far.")
        else:
            remaining = N - l*(2*l-1)
            nummatching = Y + 1
            if nummatching > remaining:
                solution = 0
                print("Not enough blocks.")
            elif 2*l + nummatching <= remaining:
                solution = 1
                print("Guaranteed after " + str(l+2+nummatching) + "; have " + str(remaining) + "; Can't miss.")
            else:
                nummatching = Y + 1
                print("Need " + str(nummatching) + " on the good side out of " + str(remaining) + ".")
                print("All matching: " + str(1/2**(nummatching)))
                for i in range(1, min(remaining - nummatching, 2*l) + 1):
                    print(str(i) + " not matching: " + str(binomial(nummatching + i - 1, i)/ 2**(nummatching+i)))
                solution = 1/2**(nummatching) + sum(binomial(nummatching + i-1, i)/2**(nummatching+i) for i in range(1, min(remaining - nummatching, 2*l)+1))
    print(solution)
    solution = float(solution)
    # Output all goes below here. Make sure to define var 'solution' 
    output_file.write("Case #" + str(case) + ": " + str(solution))
    if case < test_cases:
        output_file.write('\n')

