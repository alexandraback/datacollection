#!/usr/bin/env python3
import argparse
import queue
import math
import copy
import logging

parser = argparse.ArgumentParser(description="google code jam minesweeper")
parser.add_argument("inputfile", type=str, help="input file")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()
outfile = open(args.inputfile + ".out", "w")
if args.verbose:
    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.DEBUG)
    logging.debug("Verbose debuging mode activated")
else:
    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.INFO)


def read_input():
    f = open(args.inputfile)
    T = int(f.readline())
    for i in range(T):
        yield [int(i) for i in f.readline().split()]


def output(n, s):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)

def print_board(b):
    s = ""
    for i in b:
        s+="".join(i)
        s+="\n"
    logging.debug("printboard\n{}".format(s))
    return s

def make_board_square(R,C,M):
    board = []
    board = [["." for c in range(C)] for r in range(R)]
    mindim = min(C,R)
    N = C*R

    def mine(x,y, mines):
        if mines < 1:
            raise RuntimeError("Out of mines")
        logging.debug("mining {}, {}".format(x,y))
        if board[y][x] == "*":
            raise ValueError("Already a mine")
        board[y][x] = "*"
        logging.debug("\n{}".format(print_board(board)))
        return mines-1

    square= math.ceil(math.sqrt(N-M))
    print("square",square)
    try:
        if mindim >= square:
            for x in range(C):
                for y in range(R):
                    if C-x > square or R-y > square:
                        M=mine(x,y,M)
            print("mines left",M)
            fillcol = 0
            fillrow = 0
            if R > C:
                fillcol = M//square
                print("filling", fillcol, "col" )
                for y in range(fillcol):
                    for x in range(square):
                        M=mine(C-square+x,R-square+y,M)
            else:
                fillrow = M//square
                print("filling", fillrow, "row" )
                for y in range(square):
                    for x in range(fillrow):
                        M=mine(C-square+x,R-square+y,M)
            while M > 0:
                if M == 1:
                    logging.debug("only 1, uper left")
                    M=mine(C-square+fillrow,R-square+fillcol,M) # upper left
                else:
                    for n in range(0,square):
                        logging.debug("corners n={} fillrow={} fillcol={}".format(n,fillrow, fillcol))
                        # M=mine(C-square+fillrow,R-n-1,M)               # lower left
                        # M=mine(C-n-1,R-square+fillcol,M)      # upper right
                        if n%2==0:
                            M=mine(C-square+n//2+fillrow,R-square+fillcol,M) # upper left
                        else:
                            M=mine(C-square+fillrow,R-square+fillcol+n,M) # upper left
                    # M=mine(C-1,R-1-n,M) # lower right
        else:
            if M % R == 0 and C-M/R != 1:
                logging.debug("M % R  = 0")
                logging.debug("{}".format(M/R))
                for x in range(C):
                    for y in range(R):
                        M=mine(x,y,M)
            elif M % C == 0 and R-M/C != 1:
                logging.debug("M % C  = 0 ")
                logging.debug("{}".format(C-M/C))
                for y in range(R):
                    for x in range(C):
                        M=mine(x,y,M)
            if M < C and M < R:
                for y in range(R):
                    for x in range(C):
                        M=mine(x,y,M)

            print("not big enough to internal square")
            fillrow = 0
            fillcol = 0
            if R > C:
                fillcol = M//C
                print("filling", fillcol, "col" )
                for y in range(fillcol):
                    for x in range(C):
                        M=mine(x,y,M)
            else:
                fillrow = M//R
                print("filling", fillrow, "row" )
                for y in range(R):
                    for x in range(fillrow):
                        M=mine(x,y,M)
            print("rest")
            while M > 0:
                if M == 1:
                    M=mine(fillrow,fillcol,M)  # upper left
                else:
                    for n in range(0,M):
                        # print("n",n)
                        # print(C-n-1)
                        M=mine(C-n-1,fillcol,M)      # upper right
                        M=mine(fillrow,R-n-1,M)      # lower left
                        M=mine(fillrow+n,fillcol,M)  # upper left
                    # M=mine(C-1,R-1-n,M)
            # if M > mindim:
            #     print("MINDIM")
            #     n
            #     for y in range(mindim):
            #         for x in range(mindim):
            #             M=mine(x,y,M)
            #             M=mine(x,y,M)
            # if R < C:
            #     for y in range(R):
            #         for x in range(C):
            #             M=mine(x,y,M)
            # else:
            #     for x in range(C):
            #         for y in range(R):
            #             M=mine(x,y,M)


    except RuntimeError:
        print("done")

    board[R-1][C-1] = 'c'
    return print_board(board)

def make_board_floodfill(R,C,M, norm="MAX", midx=False, midy=False):
    board = []
    board = [["*" for c in range(C)] for r in range(R)]
    removals = (R*C)-M

    def unmine(x,y, removals):
        if removals < 1:
            raise RuntimeError("Out of removals")
        logging.debug("unmining {}, {}".format(x,y))
        if board[y][x] == ".":
            raise ValueError("Already a unminedmine")
        board[y][x] = "."
        logging.debug("\n{}".format(print_board(board)))
        return removals-1

    q = queue.PriorityQueue()
    done = []
    sx=0
    sy=0
    if midx:
        sx=C//2
    if midy:
        sy=R//2

    q.put((0,(sx,sy)))
    checked = [(sx,sy)]

    def in_range(x,y):
        if -1 < x < C and -1 < y < R:
            return True
        else:
            return False

    try:
        while q.qsize()> 0 :
            d,p = q.get()
            x,y = p
            logging.debug("{}, {}".format(d, p))
            removals=unmine(x,y,removals)
            for i,j in [(x+side, y+up) for side in (-1,0,1) for up in (-1,0,1) if not side==up==0]:
                if in_range(i,j) and (i,j) not in checked:
                    checked.append((i,j))

                    logging.debug("{}".format(checked))
                    if norm=="MAX":
                        d = max(abs(i-sx) , abs(j-sy))
                    if norm=="two":
                        d = (i-sx)**2 + (j-sy)**2
                    if norm=="one":
                        d = abs(i-sx) + abs(j-sy)
                    q.put((d,(i,j)))
    except queue.Empty:
        print("empty")
    except RuntimeError:
        logging.info("done")
    board[sy][sx] = 'c'
    return print_board(board)


def make_board(R,C,M):
    board = []
    board = [["." for c in range(C)] for r in range(R)]
    totalmines = M

    def mine(x,y, mines):
        if mines < 1:
            raise RuntimeError("Out of mines")
        logging.debug("mining {}, {}".format(x,y))
        if board[y][x] == "*":
            raise ValueError("Already a mine")
        board[y][x] = "*"
        logging.debug("\n{}".format(print_board(board)))
        return mines-1


    try:
        c = 0
        r = 0
        while M>0:
            x=c
            y=r
            while x > -1 and (y < R):
                M=mine(x,y,M)
                x -=1
                y +=1
            if c < C-1:
                # print("c+1")
                c+=1
            else:
                # print("r+1")
                r+=1

    except RuntimeError:
        print("done")

    board[R-1][C-1] = 'c'
    return print_board(board)

    pass


def possible(board):
    b = copy.copy(board)
    rows = [list(i) for i in b.strip().split("\n")]
    dim = (len(rows[0]),len(rows))
    C, R = dim
    q = queue.Queue()
    done = []
    for i,r in enumerate(rows):
        if 'c' in r:
            start = (r.index('c'),i)
    print(start)
    q.put((start))
    checked = [start]

    def is_zero(rows, x ,y):
        logging.debug("zero? {} {}".format(x,y))
        for i,j in [(x+side, y+up) for side in (-1,0,1) for up in (-1,0,1) if not side==up==0 and x+side >=0 and y+up>=0]:
            try:
                if rows[j][i] == "*":
                    logging.debug("False {} {}".format(i,j))
                    return False
            except IndexError:
                continue
        return True

    def in_range(x,y):
        if -1 < x < C and -1 < y < R:
            return True
        else:
            return False

    try:
        while q.qsize()> 0 :
            x,y = q.get()

            if is_zero(rows, x , y):
                rows[y][x] = "0"
                for i,j in [(x+side, y+up) for side in (-1,0,1) for up in (-1,0,1) if not side==up==0]:
                    if in_range(i,j) and (i,j) not in checked:
                        checked.append((i,j))
                        logging.debug("{}".format(checked))
                        q.put((i,j))
            else:
                logging.debug("{} {}".format(x,y))
                rows[y][x] = "X"
    except queue.Empty:
        print("empty")
    print("rows\n{}".format( print_board(rows).strip()))
    if any(["." in i for i in rows]):
        return False
    else:
        return True



def main():
    for n, case in enumerate(read_input(), start=1):
        print(case)
        R, C, M = case
        if M > R*C:
            output(n, "\nImpossible")
            continue

        def compute():
            for norm in ["MAX", "two", "one"]:
                for x,y in [(False,False), (True,False), (False,True), (True,True)]:
                    logging.info("with max {} x {} y {}".format(norm,x ,y))
                    b = make_board_floodfill(R,C,M, norm=norm, midx=x, midy=y)
                    if possible(b):
                        return b
            return "Impossible"

        output(n, "\n{}".format(compute().strip()))


if __name__ == "__main__":
    main()
