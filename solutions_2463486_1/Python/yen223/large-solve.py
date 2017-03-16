import argparse

palin = []
with open("numbers", "r") as f: #Precomputed
    for line in f:
        palin.append(int(line))

def solve(A, B):
    '''
    Returns the solution 
    '''
    count = 0
    for num in palin:
        if A <= num <= B:
            count += 1
    return count

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        #Read input files here
        T = int(inp.readline())
        for idx in range(1, T+1):
            A, B = [int(x) for x in inp.readline().split()]
            s = solve(A, B)
            sol = "Case #{}: {}".format(idx, s)
            solutions.append(sol)
            print sol
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
