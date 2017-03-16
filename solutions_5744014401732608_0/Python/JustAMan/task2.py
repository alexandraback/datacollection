import sys
import math

def solve(b, m):
    if (1 << (b - 2)) < m:
        return 'IMPOSSIBLE'
    b1 = int(math.log(m, 2))
    remains = m - (1 << b1)
    matrix = [[0] * b for _ in xrange(b)]
    # here goes 2**b1 paths
    for i in xrange(b1 + 1):
        for j in xrange(i + 1, b1 + 1):
            matrix[i][j] = 1
    # now add finish lines
    for i in xrange(b1 + (1 if remains > 0 else 0)):
        matrix[i + 1][b - 1] = 1
    matrix[0][b - 1] = 1
    if remains > 0:
        # now add remaining
        end = b1 + 1
        start = b1
        value = 1 << (start - 1)
        while remains > 0:
            if remains >= value:
                assert matrix[start][end] == 0
                matrix[start][end] = 1
                remains -= value
            start -= 1
            value /= 2
    # now morph the field
    return '\n'.join(['POSSIBLE'] +
            [''.join(str(cell) for cell in row) for row in matrix])

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            B, M = [int(x) for x in inp.readline().strip().split()]
            out.write('Case #%d: %s\n' % (t + 1, solve(B, M)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
