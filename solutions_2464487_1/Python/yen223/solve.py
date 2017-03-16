import argparse
from math import pi
def get_triangle(n):
    x = 2*n
    result = x * (x-1)/2
    return result

def solve(r, t):
    '''
    Returns the solution 
    '''
    low = 0
    high = t
    #print "t=", t
    while 1:
        if low == high : return (low-1)
        n = (low + high)//2
        #print n
        test = 2*n*r + get_triangle(n)
        #print "Tri(n):", get_triangle(n)
        if test <= t:
            low = n+1
        else:
            high = (low + high)//2

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
            r, t = [int(x) for x in inp.readline().split()]
            result = solve(r, t)
            sol = "Case #{}: {}".format(idx, result)
            print sol
            solutions.append(sol)
        pass
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
