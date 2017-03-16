#!/usr/bin/env python
#
# Problem: Minesweeper Master
# Language: Python
# Author: jjwon
# Usage: python thisfile.py < input.in > output.out

import fileinput

def minesweeper(testCase):
    row, col, mineNum = testCase[0], testCase[1], testCase[2]
    ogMineNum = mineNum
    if row*col <= mineNum:
        return "Impossible"
    elif col == 1:
        return "*\n"*(mineNum)+".\n"*(row-mineNum-1)+"c"
    elif row == 1:
        return "*"*(mineNum)+"."*(col-mineNum-1)+"c"
    else:
        x, y = row, col
        out = [["." for i in range(col)] for j in range(row)]
        while mineNum >= min(x,y):
            # prefer side that doesn't fuck you
            if mineNum % x == x-1 and mineNum >= y:
                for j in range(y):
                    out[x-1][j] = "*"
                mineNum -= y
                x -= 1
            elif mineNum % y == y-1 and mineNum >= x:
                for i in range(x):
                    out[i][y-1] = "*"
                mineNum -= x
                y -= 1
            elif x > y:
                for i in range(y):
                    out[x-1][i] = "*"
                mineNum -= y
                x -= 1
            else:
                for j in range(x):
                    out[j][y-1] = "*"
                mineNum -= x
                y -= 1
        # print out
        # print mineNum
        if mineNum == 0: # we have some sort of box left over
            if not isPrime(row*col-ogMineNum): # this check probably unnecessary
                return format_string(out)
        else:
            if x-mineNum == 1 and y-mineNum == 1:
                if x <= 3:
                    return "Impossible"
                else:
                    for i in range(2, x):
                        out[0][i] = "*"
                    out[1][-1] = "*"
            elif x-mineNum == 1:
                for j in range(mineNum):
                    out[x-1][y-j-1] = "*"
            else:
                for i in range(mineNum):
                    out[x-i-1][y-1] = "*"
            x -= 1
            y -= 1



        #     if x > y:
        #         if y-mineNum < 2:
        #             return "Impossible"
                
        #     else:
        #         if x-mineNum < 2:
        #             return "Impossible"
        if x > 1 and y > 1:
            return format_string(out)
        return "Impossible"

def format_string(out):
    out[0][0] = "c"
    out_str_arr = []
    for lst in out:
        out_str_arr.append("".join(lst))
    out_str = ""
    for s in out_str_arr:
        out_str += s + "\n"
    return out_str[:-1]

def isPrime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if not n & 1:
        return False
    for x in range(3, int(n**0.5)+1, 2):
        if n % x == 0:
            return False
    return True

def getAPairOfFactors(n, row, col):
    for x in range(2, int(n**0.5)+1):
        if n % x == 0:
            if x <= row and n/x <= col:
                return (x, n/x)
            elif x <= col and n/x <= row:
                return (n/x, x)
    return (-1, -1)

def main():
    numTestCase = 1
    gotNumOfTestCases = False
    testCases = []
    for line in fileinput.input():
        if not gotNumOfTestCases:
            numOfTestCases = int(line)
            gotNumOfTestCases = True
        else:
            testCases.append(line.split())
            for i in range(3):
                testCases[-1][i] = int(testCases[-1][i])
    for i in range(len(testCases)):
        print "Case #%d:" % (i+1)
        print minesweeper(testCases[i])



if __name__ == "__main__":
    main()