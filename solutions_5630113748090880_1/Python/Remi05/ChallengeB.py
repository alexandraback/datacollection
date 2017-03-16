import sys
import math
import string
import itertools

def formatOutput(n, result):
    return 'Case #' +  str(n) + ': ' + result + '\n'


def solveProblem(file):
    n = int(file.readline())
    vals = []
    for i in range(0, 2*n-1):
        row = [int(x) for x in file.readline().split()]
        vals.extend(row)

    uniques = []
    for e in vals:
        if (vals.count(e) % 2) == 1 and not e in uniques:
            uniques.append(e)
    uniques.sort()
    return " ".join(map(str,uniques))




file = open(sys.argv[1]) #open('test.txt')
output = open('output.txt', 'w')
nTests = int(file.readline())

for testNb in range(1, nTests+1):     
    res = solveProblem(file)
    output.write(formatOutput(testNb, res))
    testNb += 1
