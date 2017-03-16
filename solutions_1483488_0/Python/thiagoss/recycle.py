import sys
import math

MINZINHO = 1
MAXZAO = 2000000

listao = [None for x in range(0, MAXZAO+2)]

def move(x, digits):
    mult = 10 ** digits
    value = x / mult
    value += 10**len(str(value)) * (x % mult)
    #print 'move', x, digits, value
    return value

def compute(x):
    result = []

    for digitsmove in range(1, len(str(x))):
        newvalue = move(x, digitsmove)
        if newvalue > x:
            result.append(newvalue)

    listao[x] = result

def valid_pairs(x, b):
    total = 0
    pairs = []
    for p in listao[x]:
        if p <= b:
            pairs.append((x, p))
            total += 1
    return total, pairs

def solve(a, b):
    total = 0
    res = set([])
    for x in range(a,b+1):
        if listao[x] == None:
            compute(x)
        #print x, listao[x]
        v, p = valid_pairs(x,b)
        res |= set(p)
        total += v
    return len(res)
    #return total

i = 0
cases = int(raw_input())
while(i < cases):
    x = raw_input()
    values = x.split(' ')
    res = solve(int(values[0]), int(values[1]))
    i += 1
    sys.stdout.write("Case #" + str(i) + ': ' + str(res) + '\n')
