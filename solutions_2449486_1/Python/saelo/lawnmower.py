#!/usr/bin/env python
#coding: UTF-8
'''
Solves the Lawnmower problem of Code Jam 2013

@author: Samuel Groß
'''

INPUTFILE  = "/home/sam/Desktop/small.in"
OUTPUTFILE = "/home/sam/Desktop/small.out"


# ------------------- #
#      Functions      #
# ------------------- #

def possible(x, y, lawn):
    height = lawn[x][y]
    row_ok = True

    # check row
    for i in range(len(lawn[x])):
        if lawn[x][i] > height:
            row_ok = False
            break

    if row_ok:
        # possible
        return True

    # need to check column now
    for i in range(len(lawn)):
        if lawn[i][y] > height:
            return False

    return True


def solve(data):
    # generate "lawn"
    lawn = [ [ int(c) for c in line.split(' ') ] for line in data ]

    for i in range(len(lawn)):
        for j in range(len(lawn[i])):
            if not possible(i, j, lawn):
                return "NO"

    return "YES"



if __name__ == '__main__':
    
    infile = open(INPUTFILE, 'r')
    outfile = open(OUTPUTFILE, 'w')
    
    testcases = int(infile.readline())
    counter = 1

    for i in range(testcases):
        n, m = map(int, infile.readline().split(' '))
        input = []
        for j in range(n):
            input.append(infile.readline())     
        
        sol = solve(input)	
        print("[*] Case %i solved, %.2f%% done" % (counter, float(counter) * 100 / testcases))
        outfile.write("Case #%i: %s\n" % (counter, sol))
        counter += 1 
        
