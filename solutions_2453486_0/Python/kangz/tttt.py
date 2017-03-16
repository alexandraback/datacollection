import sys

def concat_str(args):
    s = ""
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################

def generate_lines(board):
    lines = []
    for i in range(4):
        lines.append([board[i][j] for j in range(4)])
        lines.append([board[j][i] for j in range(4)])
    lines.append([board[i][i] for i in range(4)])
    lines.append([board[3 - i][i] for i in range(4)])
    return lines


def read_input(        ):
    res = [[raw_input() for i in range(4)]]
    raw_input()
    return res

def solve(board):
    lines = generate_lines(board)
    Xwin = False
    Owin = False
    for l in lines:
        X = 0
        O = 0
        for c in l:
            if c == 'X' or c == 'T':
                X += 1
            if c == 'O' or c == 'T':
                O += 1
        if X == 4:
            Xwin = True
        if O == 4:
            Owin = True
    if Xwin:
        if Owin:
            return "Draw"
        else:
            return "X won"
    else:
        if Owin:
            return "O won"
        else:
            hasdot = any([any([board[i][j]=="." for j in range(4)]) for i in range(4)])
            if hasdot:
                return "Game has not completed"
            else:
                return "Draw"



#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

