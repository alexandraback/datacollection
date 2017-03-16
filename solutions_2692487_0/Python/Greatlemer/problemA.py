from optparse import OptionParser
import string
import math

def solve(A,N,sizes):
    if A == 1:
        return N
    sizes = sorted(sizes)
    max_moves = N
    moves = 0
    moves_to_remove = N
    for size in sizes:
        moves_to_remove -= 1
        if A > size:
            A += size
        else:
            while A <= size and moves < max_moves:
                A += (A - 1)
                moves += 1
            if A > size:
                A += size
        if moves == max_moves:
            break
        if moves + moves_to_remove < max_moves:
            max_moves = moves + moves_to_remove
    return max_moves

def main():
    parser = OptionParser()
    parser.add_option("-f", "--file", dest="filename",
                      help="read input from FILE", metavar="FILE")

    (options, args) = parser.parse_args()
    if not options.filename:
        parser.error("Must provide a filename.")
    input_file = open(options.filename, "r")
    total_cases = int(input_file.readline())
    case_number = 0
    while case_number < total_cases:
        case_number += 1
        bits = input_file.readline().split(' ')
        A = int(bits[0])
        N = int(bits[1])
        data_args = input_file.readline().split(' ')
        sizes = [int(x) for x in data_args]
        print "Case #%d: %s" % (case_number, solve(A, N, sizes))

if __name__ == "__main__":
    main()