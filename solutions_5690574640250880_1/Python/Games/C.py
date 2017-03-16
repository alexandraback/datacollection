def to_string(P):
    return "\n".join(["".join(P[r]) for r in range(len(P))])


def check(P, R, C, M):
    P = [list(row) for row in P]

    def occupied(i, j):
        return 1 if 0 <= i < R and 0 <= j < C and P[i][j] == '*' else 0

    def count(i, j):
        if 0 <= i < R and 0 <= j < C:
            if P[i][j] == '*':
                raise Exception
            if P[i][j] not in ['.', 'c']:
                return False
            P[i][j] = str(sum([occupied(r, c)
                               for r in range(i-1, i+2)
                               for c in range(j-1, j+2)]))
            return P[i][j] == "0"
        else:
            return False

    def click(i, j):
        if count(i, j):
            [click(r, c)
             for r in range(i-1, i+2)
             for c in range(j-1, j+2)]

    def ok(i, j):
        return P[i][j] not in ['.', 'c']

    click(0, 0)
    print to_string(P)
    assert(all([ok(i, j)
                for i in range(R)
                for j in range(C)]))
################################################################


def solve():
    R, C, M = [int(x) for x in input.readline().split(' ')]
    print [R, C, M]
    transpose = R > C
    if transpose:
        result = solve2(C, R, M)
        if result:
            result = map(list, zip(*result))
    else:
        result = solve2(R, C, M)

    if result:
        assert len(result) == R
        for i in range(R):
            assert len(result[i]) == C
        result = to_string(result)
        assert result.count('.') == R * C - M - 1
        assert result.count('c') == 1
        assert result.count('*') == M
        return result
    else:
        return "Impossible"


def solve2(R, C, M):
    S = R * C - M
    result = [list(row) for row in R * [C * ['*']]]
    if S == 1:
        pass
    elif R == 1:
        pass
    elif S in (2, 3, 5, 7) or (R == 2 and S % 2 != 0):
        return None  # Impossible
    if R == 2:
        for i in range(2):
            for j in range(S / 2):
                result[i][j] = '.'
    elif R == 1:
        for i in range(S):
            result[0][i] = '.'
    elif S == 1:
        pass
    elif S >= 4:
        pairs_left = S/2 - 2
        row_pairs = min((pairs_left + 1) / 2, R - 2)
        col_pairs = min(pairs_left - row_pairs, C - 2)
        for i in range(row_pairs + 2):
            result[i][0] = result[i][1] = '.'
        for j in range(col_pairs + 2):
            result[0][j] = result[1][j] = '.'
        S_left = S - 2 * row_pairs - 2 * col_pairs - 4
        for n in range(S_left):
            row = n / (C - 2)
            col = n % (C - 2)
            result[row + 2][col + 2] = '.'
    else:
        raise Exception
    result[0][0] = 'c'
    return result

################################################################

from datetime import datetime
time_start = datetime.today()


def now():
    return datetime.today() - time_start

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in', '.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in', '.out'), 'w')
n = int(input.readline())

for i in range(1, n+1):
    result = solve()
    print "Case #%d:\n%s" % (i, result)
    output.write("Case #%d:\n%s\n" % (i, result))
    output.flush()
