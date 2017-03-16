import sys
import math

def getLines():
    return [line.rstrip('\n') for line in sys.stdin]

def findNbTiles(K, C):
    number = int(math.sqrt(K)) + 1
    while number > 0 and number ** C != K:
        number -= 1
    return number

assert(findNbTiles(27, 3) == 3)
assert(findNbTiles(64, 3) == 4)

def solve(K, C, S):
    if K == S:
        return ' '.join([str(index + 1) for index in range(0, S)])
    # print('K C S', K, C, S)
    return 'IMPOSSIBLE'

lines = getLines()
nbCases = int(lines.pop(0))

for case in range(0, nbCases):
    K, C, S = map(int, lines.pop(0).split(' '))
    answer = solve(K, C, S)
    print("Case #", (case + 1), ": ", answer, sep="")
