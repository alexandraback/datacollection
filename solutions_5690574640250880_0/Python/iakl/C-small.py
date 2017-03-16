# IO file paths
file_in = "C-small-attempt1.in"
file_out = "C-small-attempt1.out"


mine = '*'
empty = '.'
click = 'c'

# Generates a board full of mines
def MakeBoard(R, C):
    b = []
    for _ in xrange(0, R):
        row = []
        for _ in xrange(0,  C):
            row.append(mine)
        b.append(row)
    return b


# Solves the problem
def Solve(R, C, M):
    # Find out how many cells should be empty
    F = R * C - M

    if 1 == F:
        return SolveSingleEmpty(R, C)

    if 1 == R or 1 == C:
        return SolveRod(R, C, F)

    b = SolveRect(R, C, F)
    if None != b:
        return b

    b = SolveRectPlusRods(R, C, F)
    if None != b:
        return b
    
    return None

def SolveSingleEmpty(R, C):
    b = MakeBoard(R, C)
    b[0][0] = click
    return b

def SolveRod(R, C, F):
    b = MakeBoard(R, C)
    if 1 == R:
        for j in range(0, F):
            b[0][j] = empty
    elif 1 == C:
        for i in range(0, F):
            b[i][0] = empty
    else:
        return None
    b[0][0] = click
    return b

def SolveRect(R, C, F):
    # A rectangle can always be revealed by one click
    for r in range(2, R + 1):
        if 0 == F % r:
            c = F / r
            if 1 < c and c <= C:
                # A suitable rectangle established
                b = MakeBoard(R, C)
                for i in range(0, r):
                    for j in range(0, c):
                        b[i][j] = empty
                b[0][0] = click
                return b
    return None

def SolveRectPlusRods(R, C, F):
    # Case of vertical rod
    for r in range(2, R + 1):
        d = F % r
        if 1 == d:
            c = F / r
            if 2 < r and 2 < c and c < C:
                # A suitable rectangle plus two rods established
                b = MakeBoard(R, C)
                for i in range(0, r):
                    for j in range(0, c):
                        b[i][j] = empty
                b[r - 1][c - 1] = mine
                for i in range(0, d + 1):
                    b[i][c] = empty
                b[0][0] = click
                return b
        if 1 < d:
            c = F / r
            if 1 < c and c < C:
                # A suitable rectangle plus a rod established
                b = MakeBoard(R, C)
                for i in range(0, r):
                    for j in range(0, c):
                        b[i][j] = empty
                for i in range(0, d):
                    b[i][c] = empty
                b[0][0] = click
                return b
    # Case of vertical rod
    for c in range(2, C + 1):
        d = F % c
        if 1 == d:
            r = F / c
            if 2 < c and 2 < r and r < R:
                # A suitable rectangle plus two rods established
                b = MakeBoard(R, C)
                for i in range(0, r):
                    for j in range(0, c):
                        b[i][j] = empty
                b[r - 1][c - 1] = mine
                for i in range(0, d + 1):
                    b[r][j] = empty
                b[0][0] = click
                return b
        if 1 < d:
            r = F / c
            if 1 < r and r < R:
                # A suitable rectangle plus a rod established
                b = MakeBoard(R, C)
                for i in range(0, r):
                    for j in range(0, c):
                        b[i][j] = empty
                for j in range(0, d):
                    b[r][j] = empty
                b[0][0] = click
                return b
    return None

# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    k = 0
    T = int(lines[0])
    k = k + 1
    for t in range(0, T):
        values = lines[k].rstrip().split(' ')
        k = k + 1
        R, C, M = int(values[0]), int(values[1]), int(values[2])
        result = ''
        board = Solve(R, C, M)
        if None == board:
            result = "Impossible\n"
        else:
            for i in range(0, R):
                for j in range(0, C):
                    result = result + board[i][j]
                result = result + '\n'
        fout.write("Case #" + str(t + 1) + ":\n" + result)
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
