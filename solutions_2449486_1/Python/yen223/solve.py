import argparse

def solve(lawn):
    '''
    Returns the solution 
    '''
    #Insert code here
    row_length = len(lawn)
    col_length = len(lawn[0])
    row_cut = []
    for row in lawn:
        row_cut.append(max(row))

    col_cut = []
    for x in range(col_length):
        temp_max = 0
        for row in lawn:
            if row[x] > temp_max:
                temp_max = row[x]
        col_cut.append(temp_max)

    for x in range(col_length):
        for y in range(row_length):
            if lawn[y][x] != min(col_cut[x], row_cut[y]):
                return "NO"
    else:
        return "YES"

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
        T = int(inp.readline())
        for idx in range(1, T+1):
            lawn = []
            N, M = [int(x) for x in inp.readline().split()]
            for i in range(N):
                lawn.append([int(y) for y in inp.readline().split()])
            s = solve(lawn)
            sol = "Case #{}: {}".format(idx, s)
            print sol
            solutions.append(sol)
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
