#!/usr/bin/env python


# use a board dict
 
from __future__ import print_function
import sys
import profile 

neighbors_cache = []
 
def read_int():
    return int(input())
 
 
def read_ls():
    s = sys.stdin.readline()
    return [int(x) for x in s.split()]
 



# returns the index of the given r,c, or -1 if it is out of bounds.
def getidx(rows,cols,r,c):
    if (r < 0 or c < 0 or r >= rows or c >= cols):
        return -1
    #print("r,c,row,col {0} {1} {2} {3} = {4}".format(r,c,rows,cols, r*rows+c))
    return r*cols + c

def getpos(rows,cols,pos1):
    r = pos1 // cols
    c = pos1 % cols
    return (r,c)

def print_board(board, rows, cols):
    s=""
    for i,x in enumerate(board):
        if i > 0 and i % cols == 0:
            s += "\n"

        if x == 2:
            s += "c"
        elif x == 0:
            s += "*"
        elif x == 1:
            s += "."

    return s


# Click through a board recursively and see how much we can clear
def click_board( board, board_clicked, neighbors, rows, cols, clickpos ):
    if board_clicked == None:
        board_clicked = [ 0 for x in board ]

    board_clicked[clickpos] = 1

    nidx = get_neighbors_idx(rows, cols, clickpos, neighbors)

    count=0
    for idx in nidx:
        if board[idx] == 0:
            count += 1

    # If all the surrounding tiles have no mines
    if count == 0:
        for idx in nidx:
            if board_clicked[idx] == 0:
                board_clicked = click_board(board, board_clicked, neighbors, rows, cols, idx)


    return board_clicked


def place_empty( board, neighbors, rows, cols, n_term, start, nextpos, empty_count ):
    # Mark this spot empty
    if start == nextpos:
        board[nextpos] = 2
    else:
        board[nextpos] = 1

    # If we marked enough places empty, return None for bad board
    empty_count += 1
    if empty_count == n_term:
        if n_term == 1:
            return board

        board_clicked = click_board(board, None, neighbors, rows, cols, start)
        if sum(board_clicked) == n_term:
            return board
        else:
            return None

    (r1,c1) = getpos(rows,cols,nextpos)
    for offset in neighbors:
        idx = getidx(rows,cols, r1+offset[0], c1+offset[1])
        # if out-of-bounds or cell was already marked empty
        if idx == -1:
            continue
        if board[idx] != 0:
            continue

        board_out = place_empty( list(board), neighbors, rows, cols, n_term, start, idx, empty_count)
        if board_out != None:
            return board_out
            


def get_neighbors_idx(rows, cols, idx, neighbors):
    neighbors1 = []
    (r1,c1) = getpos(rows,cols,idx)
    for offset in neighbors:
        idx = getidx(rows,cols, r1+offset[0], c1+offset[1])
        # if out-of-bounds or cell was already marked empty
        if idx >= 0:
            neighbors1.append(idx)

    return neighbors1

def count_neighbors(board, rows, cols, idx, neighbors):
    count=0
    for idx in get_neighbors_idx(rows, cols, idx, neighbors):
        if board[idx] == 0:
            count += 1
    return count    

#    (r1,c1) = getpos(rows,cols,idx)
#    for offset in neighbors:
#        idx = getidx(rows,cols, r1+offset[0], c1+offset[1])
#        # if out-of-bounds or cell was already marked empty
#        if idx == -1:
#            continue
#        if board[idx] == 0:
#            count += 1
#
#    return count    
 
def run(rows,cols,m, debug=False):
    board = [ 0 for x in range(rows*cols) ]
    neighbors = [ (-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1) ]
    num_empty = rows*cols - m

    # starting position
    for start in range(rows*cols):
        
        board_out = place_empty( list(board), neighbors, rows, cols, num_empty, start, start, 0 )
        if board_out != None:
            s = print_board(board_out, rows, cols)
            if debug:
                s = "Possible ({0}, {1}, {2})\n".format(rows,cols,m) + s
            return s
    
    if debug:
        return "Impossible ({0}, {1}, {2})".format(rows,cols,m)
    else:
        return "Impossible"
 
 
def main():
    for i in range(read_int()):
        # input data
        (r,c,m) = read_ls()
 
        # evaluate
        result = run(r,c,m, False)
 
        # output
        print("Case #%d:\n%s" % (i + 1, result))
 
if __name__ == "__main__":
    #profile.run('main()')
    sys.exit(main())
