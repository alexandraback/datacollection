import sys
import math

def solve(surprises, best, values):
    values.sort()
    values.reverse()
    surprises = int(surprises)
    best = int(best)
    count = 0
    high = 3*best - 2
    low = max(best,3*best - 4) #1 is a corner case
    for v in values:
        v = int(v)
        if v >= high:
            count += 1
        elif v >= low and surprises:
            count += 1
            surprises -= 1
    return count

i = 0
cases = int(raw_input())
while(i < cases):
    x = raw_input()
    values = x.split(' ')
    if values[0] == 0:
        res = 0
    else:
        res = solve(values[1], values[2], values[3:])
    i += 1
    sys.stdout.write("Case #" + str(i) + ': ' + str(res) + '\n')
