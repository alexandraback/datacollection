#!/usr/bin/env python2
import sys

def read_board(iterable):
    board = [list(next(iterable)[:-1]) for _ in range(4)]
    # discard the newline
    try:
        next(iterable)
    except StopIteration:
        pass
    return board


def state_hist(state):
    hist = dict()
    for sym in state:
        if sym not in hist:
            hist[sym] = 0
        hist[sym] += 1
    return hist


def hist_status(hist):
    # Can't be a winning state if both X and O exist
    if 'X' in hist and 'O' in hist:
        return False
    elif 'X' in hist:
        try:
            if (hist['X'] == 4 or hist['X'] == 3 and hist['T'] == 1):
                return 'X'
        except:
            return None
    elif 'O' in hist:
        try:
            if (hist['O'] == 4 or hist['O'] == 3 and hist['T'] == 1):
                return 'O'
        except:
            return None
    else:
        return None

# Basically, we only need to check if there's a winning situation starting at
# ++++
# +...
# +...
# +...
# 
# TODO: make a decent DP solution
def get_status(board):
    winner = None
    # check vert
    for col in range(4):
        winner = hist_status(state_hist([board[r][col] for r in range(4)]))
        if winner:
            break
    # check horiz
    if not winner:
        for row in range(4):
            winner = hist_status(state_hist(board[row]))
            if winner:
                break
    # check up-left to bottom-right diagonal
    if not winner:
        winner = hist_status(state_hist([board[i][i] for i in range(4)]))
    # check up-right to bottom-left diagonal
    if not winner:
        winner = hist_status(state_hist([board[i][3-i] for i in range(4)]))
    # if there is still no winner, it's either a draw or not completed
    # TODO: we actually already check the whole field once during the search for a winner
    # we can look for '.' there as well and then decide this instantly
    if not winner:
        for row in board:
            for sym in row:
                if sym == '.':
                    return "Game has not completed"
        return "Draw"
    else:
        return "%s won" % winner


def main():
    num_cases = int(next(sys.stdin))
    for i in range(num_cases):
        board = read_board(sys.stdin)
        print "Case #%d: %s" % (i + 1, get_status(board))


if __name__ == '__main__':
    main()
