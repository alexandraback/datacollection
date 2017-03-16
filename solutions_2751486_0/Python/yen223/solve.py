import argparse
def get_sum(mark, next_mark):
    start,end = mark
    next_start = next_mark[0]
    return (x+1) * (next_start - end)

def solve(name, n):
    '''
    Returns the solution 
    '''
    start = -1
    marks = []
    print name, n
    for i, val in enumerate(name):
        if val not in 'aeiou':
            if start == -1:
                start = i
            if i- start +1 == n:
                marks.append((start, i))
                start += 1
        else:
            start = -1
    print marks
    substrings = set()
    for mark in marks:
        for s in range(mark[0] + 1):
            for e in range(mark[1], len(name)):
                print (s,e)
                substrings.add((s,e))
    return len(substrings)

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
            name, n = inp.readline().split()
            n = int(n)
            s = solve(name, n)
            sol = "Case #{}: {}".format(idx, s)
            print sol
            solutions.append(sol)
        pass
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
