import sys
import math


def check(x, r, c):
    if r < c:
        r, c = c, r

    if (r * c) % x != 0: #check the size
        return True

    if x >= 7: # create a circle
        return True

    if x > r: # create a long bar
        return True

    if x > 2 * c: # create a long L bar
        return True

    if x <= 2: #always fit the board, size is already guaranteed
        return False

    if x == 4 and c == 2:
        return True

    if x == 6 and c == 3:
        return True

    if c >= 3 and x <= 3:
        return False

    if c >= x:
        return False

    return False


def solve(x, r, c):
    if check(x, r, c):
        return "RICHARD"
    else:
        return "GABRIEL"


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        x, r, c = [int(x) for x in input().split(' ')]
        print("Case #%i: %s" % (caseNr, solve(x, r, c)))