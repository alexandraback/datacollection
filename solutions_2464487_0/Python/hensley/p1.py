import numpy as np
import os
import re

def is_possible(board):
    #print board
    if (board.size == 1):
        return 1
    minval = np.amin(board)
    maxval = np.amax(board)
    mylist = np.unique(board)
    if (minval == maxval):
        return 1
    for w in range(len(mylist)):
        for i in range(len(board[:,0])):
            for j in range(len(board[0,:])):
                if (board[i,j] == mylist[w]):
                    rowsum = 0
                    colsum = 0
                    for k in range(len(board[i,:])):
                        if (board[i,k] <= mylist[w]):
                            colsum += 1
                    for k in range(len(board[:,j])):
                        if (board[k,j] <= mylist[w]):
                            rowsum += 1
                        
                    if (colsum != len(board[i,:]) and rowsum != len(board[:,j])):
                        return 0
                    
    return 1

def main():
    infile = "A0.in"
    inf = open(infile, 'r')

    outfile = "A0.out"
    outf = open(outfile, 'w')

    lnum = 1
    case = 0
    totcase = 0
    for line in inf:
        if (lnum == 1):
            totcase = int(line.split()[0])
        else :
            case += 1
            lstring = line.split()
            r = long(lstring[0])
            t = long(lstring[1])
            N = long(np.floor( (-(2.0*r - 1.0) + np.sqrt(4.0*r**2 - 4.0*r + 1.0 + 8.0*t))/4.0) - 2)
            while(2*N*N + 2*r*N - N <= t):
                N += 1
            N -= 1
            outf.write("Case #" + str(case) + ": " + str(N) + "\n")
        lnum += 1
            


if __name__ == '__main__':
     main()
