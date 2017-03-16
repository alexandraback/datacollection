#!/usr/bin/env python
import sys
import logging

def main():
    import argparse
    parser = argparse.ArgumentParser(description='')
    parser.add_argument('input_file',help='The program\'s input file.')
    parser.add_argument('-o','--outfile',required=False,help='The program\'s output file.')
    parser.add_argument('-d','--debug',help='Debug logging level',action="store_true")
    
    args = parser.parse_args()

    if args.debug:
        logging.basicConfig(level=logging.DEBUG)

    f = open(args.input_file,'r')
    fout = sys.stdout
    if args.outfile:
        fout = open(args.outfile,'w')

    cases = int(f.readline())

    for case_number in range(cases):
        logging.debug('Case %d',case_number+1)
        board = []
        for i in range(4):
            board.extend(f.readline().strip())
        f.readline()

        win = test_horizontal_win(board)
        complete = False
        if not win:
            win = test_vertical_win(board)
        if not win:
            win = test_diagonal_win(board)
        if not win:
            complete = test_finished(board)

        if win:
            phrase = '%s won'%win
        else:
            if complete:
                phrase = 'Draw'
            else:
                phrase = 'Game has not completed'

        print >>fout,'Case #%d: %s'%(case_number+1,phrase)

def test_finished(board):
    if '.' in board:
        return False
    else:
        return True

def test_win(row):
    if '.' not in row:
        if 'X' not in row:
            return 'O'
        if 'O' not in row:
            return 'X'

    return None

def test_horizontal_win(board):
    win = None
    for i in range(4):
        win = test_win(board[4*i:4*i+4])
        if win:
            break

    return win

def test_vertical_win(board):
    win = None
    for i in range(4):
        win = test_win(board[i:16:4])
        if win:
            break

    return win

def test_diagonal_win(board):
    win = test_win(board[0:16:5])
    if not win:
        win = test_win(board[3:13:3])

    return win


if __name__=='__main__':
    main()
