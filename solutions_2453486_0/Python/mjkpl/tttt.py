__author__ = 'michal'
import sys
import math


def is_winning_state(state):

    O_num = state.count("O")
    X_num = state.count("X")
    T_num = state.count("T")

    assert(O_num >= 0 and O_num <= 4)
    assert(X_num >= 0 and X_num <= 4)
    assert(T_num >= 0 and T_num <= 4)

    if O_num > 0 and X_num > 0:
        return None

    if O_num + T_num == 4:
        return 'O'

    if X_num + T_num == 4:
        return 'X'


def tttt(board):

    empties = 0

    # check rows
    for row in range(4):
        state = []

        for col in range(4):
            state.append(board[(row, col)])

        ret = is_winning_state(state)
        if ret == 'X':
            return 'X'

        if ret == 'O':
            return 'O'

        empties += state.count('.')


    #check cols
    for col in range(4):
        state = []

        for row in range(4):
            state.append(board[(row, col)])

        ret = is_winning_state(state)
        if ret == 'X':
            return 'X'

        if ret == 'O':
            return 'O'

        empties += state.count('.')


    #diagonals
    state = [board[(0, 0)], board[(1, 1)], board[(2, 2)], board[(3, 3)],]


    ret = is_winning_state(state)

    if ret== 'X':
        return 'X'

    if ret == 'O':
        return 'O'

    empties += state.count('.')


    #diagonals
    state = [board[(3, 0)], board[(2, 1)], board[(1, 2)], board[(0, 3)],]

    ret = is_winning_state(state)
    if ret == 'X':
        return 'X'

    if ret == 'O':
        return 'O'

    empties += state.count('.')

    if empties > 0:
        return "N"

    if empties == 0:
        return "D"



if __name__=="__main__":

    file_out = None
    if len(sys.argv) >= 2:
        file = open(sys.argv[1])
        if len(sys.argv) == 3:
            file_out = open(sys.argv[2], 'w')
    else:
        file = sys.stdin

    cases = int(file.readline())

    for case in range(cases):

        board = {}

        for row in range(4):
            line = file.readline()

            col = 0
            for symbol in line.strip():
                assert(symbol == 'X' or symbol == 'O' or symbol == '.' or symbol == 'T')
                board[(row, col)] = symbol
                col += 1

        file.readline()

        result = tttt(board)

        results = {"X": "X won",
                   "O": "O won",
                   "D": "Draw",
                   "N" : "Game has not completed"}

        out = "Case #%i: %s" % (case + 1, results[result])

        print out
        if file_out != None:
            file_out.write(out + '\n')



