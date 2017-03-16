import argparse
import math
cache = {}
def is_palindrome(num):
    if num in cache:
        return cache[num]
    s = str(num)
    l = len(s)
    if l == 1: return True
    print "Checking", s
    if s == s[::-1]:
        cache[num] = True
        return True
    else:
        cache[num] = False
        return False

def solve(A, B):
    '''
    Returns the solution 
    '''
    num = int(math.ceil(math.sqrt(A)))
    count = 0
    while 1:
        square = num ** 2
        if square > B: break
        if not is_palindrome(num): 
            num += 1
            continue
        if is_palindrome(square):
            print "{} is a palindrome".format(square)
            count += 1
        num += 1
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
        T = int(inp.readline())
        for idx in range(1, T+1):
            A, B = [int(x) for x in inp.readline().split()]
            s = solve(A, B)
            sol = "Case #{}: {}".format(idx, s)
            print sol
            solutions.append(sol)
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
