#!/usr/bin/env python
#coding: UTF-8
'''
I/O framework for the Google Code Jam contest

Created on Apr 25, 2012

@author: Samuel Groß
'''

INPUTFILE  = "/home/sam/Desktop/small.in"
OUTPUTFILE = "/home/sam/Desktop/small.out"

LINES_PER_PROBLEM = 4


# ------------------- #
#      Functions      #
# ------------------- #

def check(line):
    """
    check one set of 4 characters for a valid combination
    """

    curr = ''
    for c in line:
        if c == 'X' or c == 'O':
            if curr == c or curr == '':
                curr = c
            elif c == 'X' and curr == 'O' or c == 'O' and curr == 'X':
                curr = '-'
        if c == '.':
            return c

    return curr

     
def solve(data):
    # parse board
    board = [[ c for c in line ] for line in data ] 

    lines = []
    line = '' 

    # check each row
    for row in board:
        for c in row:
            line += c
        lines.append(line)
        line = ''

    # check each column
    for i in range(4):
        for j in range(4):
            line += board[j][i]
        lines.append(line)
        line = ''

    # check two diagonals
    line2 = ''
    for i in range(4):
        line += board[i][i]
        line2 += board[i][3-i]
    lines.append(line)
    lines.append(line2)

    poss_not_over = False
    for line in lines:
        res = check(line)
        if res == 'X' or res == 'O':
            # we have a winner
            return "%s won" % res
        if res == '.':
            poss_not_over = True


    # no one has one so far
    if poss_not_over:
        return "Game has not completed"
    else:
        return "Draw"





if __name__ == '__main__':
    
    infile = open(INPUTFILE, 'r')
    outfile = open(OUTPUTFILE, 'w')
    
    testcases = int(infile.readline())
    counter = 1


    for i in range(testcases):
        input = []
        for j in range(LINES_PER_PROBLEM):
            input.append(infile.readline())     
        
        sol = solve(input)  
        print("[*] Case %i solved, %.2f%% done" % (counter, float(counter) * 100 / testcases))
        outfile.write("Case #%i: %s\n" % (counter, sol))
        counter += 1 

        if counter <= testcases:
            infile.readline()   # empty line
 
