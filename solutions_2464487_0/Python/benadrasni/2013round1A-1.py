import sys
import math

def solve():

    return ""

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    line = sys.stdin.readline()
    r = int(line.split()[0])
    t = int(line.split()[1])

    i = 1
    while t >= 2*i*i + i*(2*r-1):
        i *= 2
    i = int(i/2)
    step = int(i/2)
    while step >= 1:
        if t >= 2*(i+step)*(i+step) + (i+step)*(2*r-1):
            i += step
        else:
            step = int(step/2)

    # i = 0
    # while t >= 2*r + 1:
    #     t -= 2*r + 1
    #     r += 2
    #     i += 1

    print ('Case #' + repr(casenum) + ': ' + repr(i))