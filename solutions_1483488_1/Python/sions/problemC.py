import math
import sys

def read_case(line):
    arr = [int(i) for i in line.split()]
    return arr


def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines.next())))

    return cases

def shift_num(n, digits, shift_by):
    exp = 10 ** shift_by
    return (n // exp) + ((n % exp) * (10 ** (digits - shift_by)))

def solve(arr):
    A, B = arr
    num_digits = int(math.floor(math.log10(A))) + 1
    
    num_pairs = 0
    
    for i in xrange(A, B + 1):
        pairs = set()
        for shift in range(1, num_digits):
            n = i
            m = shift_num(n, num_digits, shift)
            if n < m and m <= B and (n,m) not in pairs:
                num_pairs += 1
                pairs.add((n,m))
    
    return num_pairs

if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))
