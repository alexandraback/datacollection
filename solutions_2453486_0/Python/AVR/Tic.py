import sys


def check(seq):
    type = -1
    for i in seq:
        if i == '.':
            return -1
        if i == 'X':
            if type == 0:
                return -2
            else: type = 1
        if i == 'O':
            if type == 1:
                return -2
            else: type = 0
    return type


def main():
    infile = open(sys.argv[1])
    outfile = open(sys.argv[1][:-2] + 'out', 'w')
    numcases = int(infile.readline())

    for case in range(numcases):
        board = []
        empty = False
        won = 'Draw'
        for i in range(4):
            board += [infile.readline().strip()]
        state = -1
        infile.readline()

        print(board)
        for row in board:
            state = check(row)
            if state == -1:
                empty = True
            elif state == 0:
                won = 'O won'
            elif state == 1:
                won = 'X won'
        for n in range(4):
            col = [board[i][n] for i in range(4)]
            state = check(col)
            if state == -1:
                empty = True
            elif state == 0:
                won = 'O won'
            elif state == 1:
                won = 'X won'
        for n in range(2):
            diag = [board[i][i*n + (n-i-1)*(1-n)] for i in range(4)]
            state = check(diag)
            if state == -1:
                empty = True
            elif state == 0:
                won = 'O won'
            elif state == 1:
                won = 'X won'

        if won == 'Draw' and empty == True:
            newone = 'Game has not completed'
        else: newone = won

        print('Case #%d:' % (case + 1), newone, file=outfile)





if __name__ == '__main__':
    main()
