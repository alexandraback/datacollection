import sys

def solve(line):
    K, C, S = [int(i) for i in line.split()]
    if K > C * S:
        return 'IMPOSSIBLE'
    solution = []
    i = 0
    while i < K:
        current_solution = K ** (C - 1) * i
        for j in xrange(C):
            if i + j == K:
                break
            current_solution += K ** j * (i + j)
        solution.append(current_solution)
        i += C
    return ' '.join([str(s + 1) for s in solution])

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as fd:
        lines = [line.strip() for line in fd.readlines()]
    for test_case in xrange(1, len(lines)):
        solution = solve(lines[test_case])
        print 'Case #%d: %s' % (test_case, solution)
