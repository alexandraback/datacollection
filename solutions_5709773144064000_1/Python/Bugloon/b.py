import math
import sys

if __name__ == "__main__":

    testcases = int(sys.stdin.readline())

    for case in xrange(1, testcases+1):

        C, F, X = map(float, sys.stdin.readline().split())

        t = 0
        r = 2

        while C/r + C/F < X/r:
            t += C/r
            r += F

        t += X/r

        print("Case #{}: {:.7f}".format(case, t))
