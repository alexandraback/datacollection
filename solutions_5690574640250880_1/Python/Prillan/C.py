##
# CODEJAM
# prillan91
##
import sys


def solveSingle(f):
    R, C, M = tuple(int(x) for x in f.readline().strip().split(' '))

    print(R, C, M)

    r = R
    c = C
    m = M

    while m > 0 and r > 0 and c > 0:
        if m >= c and m >= r:
            if c >= r:
                m -= r
                c -= 1
            else:
                m -= c
                r -= 1
        elif m >= c:
            m -= c
            r -= 1
        elif m >= r:
            m -= r
            c -= 1
        elif m > r*c:
            print("Impossible,\tm > r*c")
            return "Impossible"
        else:
            break

    print(r,c,m)

    right = c != C
    down = r != R

    # Build board
    row = ['.']*c
    row += ["*"]*(C-c)

    board = [row] * r
    board += [['*']*C]*(R-r)

    # Avoid copying references
    for i in range(len(board)):
        board[i] = list(board[i])

    board[0][0] = 'c'

    if C == 1 or R == 1:
        return board

    if c == 1 and r == 1 and m == 0:
        return board

    if c == 1 or r == 1:
        print("Impossible,\tc == 1 or r == 1")
        return "Impossible"

    # At least 2 rows and 2 cols

    if c == 2 and r == 2 and m == 0:
        return board
    if (c == 2 or r == 2) and m > 0:
        print("Impossible,\t(c == 2 or r == 2) and m > 0")
        return "Impossible"

    # c > 2, r > 2

    i = c-1

    while m > 0 and i > 1:
        board[r-1][i] = '*'
        i -= 1
        m -= 1

    j = r-2

    while m > 0 and j > 1:
        try:
            board[j][c-1] = '*'
        except:
            print(board_to_str(board))
            print(j, c, m)
            exit(1)
        j -= 1
        m -= 1

    if m > 0:
        print("Impossible,\tm > 0")
        return "Impossible"

    return board

def board_to_str(board):
    return '\n'.join(''.join(row) for i, row in enumerate(board))

def solve():
    f = open(sys.argv[1])
    o = open(sys.argv[1] + ".out", 'w')
    T = int(f.readline())

    for t in range(T):
        print t + 1
        case = solveSingle(f)
        if not isinstance(case, str):
            case = board_to_str(case)
            print(case)
        o.write("Case #" + str(t + 1) + ": \n" + str(case) + "\n")


solve()
