import time

file_in = file('test.in', 'r')
file_out = file('test.out', 'w')

def main():
    n_case = int(file_in.readline())
    for case in range(1, n_case + 1):
        solveCase(case)

def solve_1(row, col, mine):
    if row == 1:
        return "*" * mine + "." * (col - mine - 1) + "c"
    else:
        return "*\n" * mine + ".\n" * (row - mine - 1) + "c"

def solve_2(row, col, mine):
    if row * col - mine == 1:
        if row == 2:
            return "*" * col + "\n" + "*" * (col - 1) + "c"
        elif col == 2:
            return "**\n" * (row - 1) + "*c"
    elif row * col - mine == 2:
        return "Impossible"
    if mine % 2 == 1:
        return "Impossible"
    elif row == 2:
        return (
            "*" * (mine / 2) + "." * (col - mine / 2) + "\n" +
            "*" * (mine / 2) + "." * (col - mine / 2 - 1) + "c")
    elif col == 2:
        return "**\n" * (mine / 2) + "..\n" * (row - mine / 2 - 1) + ".c"

def stringify(board):
    return ''.join([(''.join(row) + "\n") for row in board]).strip()

def solve_3(row, col, mine):
    free = row * col - mine
    if free == 1:
        return ("*" * col + "\n") * (row - 1) + ("*" * (col - 1) + "c")
    elif free == 4:
        return (("*" * col + "\n") * (row - 2) 
            + ("*" * (col - 2) + "..\n")
            + ("*" * (col - 2) + ".c"))
    elif free == 2 or free == 3 or free == 5 or free == 7:
        return "Impossible"
    elif free == 6:
        return (("*" * col + "\n") * (row - 2) 
            + ("*" * (col - 3) + "...\n")
            + ("*" * (col - 3) + "..c"))
    elif free == 8:
        return (("*" * col + "\n") * (row - 3)  
            + ("*" * (col - 3) + "*..\n")
            + ("*" * (col - 3) + "...\n")
            + ("*" * (col - 3) + "..c"))
    else:
        board = [["."] * col for i in range(row)]
        board[row - 1][col - 1] = "c"

        if mine == 0:
            return stringify(board)

        # fill r-2, c-2 rect
        for r in range(row - 2):
            for c in range(col - 2):
                board[r][c] = "*"
                mine -= 1
                if mine == 0:
                    return stringify(board)

        # fill right edges:
        for r in range(row - 3):
            for c in range(col - 2, col):
                board[r][c] = "*"
                mine -= 1
                if mine == 0:
                    if c == col - 2:
                        board[row - 3][col - 3] = "."
                        board[r][c + 1] = "*"
                    return stringify(board)

        # file bottom edges:
        for c in range(col - 3):
            for r in range(row - 2, row):
                board[r][c] = "*"
                mine -= 1
                if mine == 0:
                    if r == row - 2:
                        board[row - 3][col - 3] = "."
                        board[r + 1][c] = '*'
                    return stringify(board)

        return stringify(board)
        print "CAN'T REACH THIS PLACE!!! IMPOSSIBRUUU!!!"

def solveCase(case_number):
    #in
    r, c, m = map(int, file_in.readline().split())
    print case_number, r, c, m

    #main
    if (r == 1) or (c == 1):
        print 'solve 1'
        result = solve_1(r, c, m)
    elif (r == 2) or (c == 2):
        print 'solve 2'
        result = solve_2(r, c, m)
    else:
        print 'solve 3'
        result = solve_3(r, c, m)
    #out
    file_out.write("Case #" + repr(case_number) + ":\n" + result + "\n")

if __name__ == '__main__':
    startTime = time.clock()
    main()
    print (time.clock() - startTime)