import sys
from math import ceil
from math import floor
input = open('///Users/Zetilov/Downloads/D-small-attempt2.in.txt', 'r')
output = open('output.txt', 'w')


#input = sys.stdin
#output = sys.stdout


t = int(input.readline())
for z in range(t):
    x, r, c = map(int, input.readline().split())
    if x == 4 and min(r, c) < 3 or x == 3 and min(r, c) == 1:
        res = "RICHARD"
    elif r * c % x == 0:
        res = "GABRIEL"
    else:
        res = "RICHARD"
    print('Case #', z + 1, ': ', end = '', sep = '', file = output)
    print(res, file = output)