import math
import sys

def read_case(line):
    A, B = [int(i) for i in line.split()]
    return A, B


def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines.next())))

    return cases

def palindrom(num):
    as_str = str(num)
    return as_str == ''.join(reversed(as_str))
    

def solve(case):
    A, B = case
    start = int(math.ceil(math.sqrt(A)))
    end = int(math.floor(math.sqrt(B)))
    total = 0
    
    for i in xrange(start, end + 1):
        if palindrom(i) and palindrom(i*i):
            total += 1
    
    return total

if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))
