import sys
import math
import string
import itertools

def formatOutput(n, result):
    return 'Case #' +  str(n) + ': ' + result + '\n'

def getNextLeft(s, cur_max):
    for i in range(1, len(s)):
        if s[i] >= cur_max:
            return s[i]
    return None


def solveProblem(line):
    line = line.strip('\n')
    result = ''
    c = ''
    cur_max = line[0]
    has_left = True
    while has_left:
        c = getNextLeft(line, cur_max)
        has_left = (c != None)
        if has_left:
            result = c + result
            cur_max = c
            line = line.replace(c, '', 1)
    result += line
    return result



file = open(sys.argv[1]) #open('test.txt')
output = open('output.txt', 'w')
nTests = int(file.readline())

testNb = 1
for line in itertools.islice(file, 0, nTests+1):     
    res = solveProblem(line)
    output.write(formatOutput(testNb, res))
    testNb += 1
output.close()
