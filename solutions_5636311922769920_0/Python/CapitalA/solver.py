import sys

def solve_case(line):
    K, C, S = [int(i) for i in line.split()]
    if K != S:
        return 'IMPOSSIBLE'
    solution = []
    for i in xrange(S):
        solution.append(str(K ** (C - 1) * i + 1))
    return ' '.join(solution)

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as fd:
        lines = [line.strip() for line in fd.readlines()]
    for test_case in xrange(1, len(lines)):
        solution = solve_case(lines[test_case])
        print 'Case #%d: %s' % (test_case, solution)
