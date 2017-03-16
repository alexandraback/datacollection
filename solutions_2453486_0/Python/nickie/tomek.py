#!/usr/bin/env python

class FoundX: pass
class FoundO: pass

def parse():
    a = []
    full = True
    for i in range(4):
        s = raw_input().strip()
        a.append(s)
        if '.' in s: full = False
    raw_input()
    return (a, full)

def examine(l):
    if '.' in l: return
    hasO = 'O' in l
    hasX = 'X' in l
    if hasO and hasX: return
    if hasO: raise FoundO
    raise FoundX    

def solve(a, full):
    try:
        for i in range(4): examine(a[i])
        for j in range(4): examine([a[i][j] for i in range(4)])
        examine([a[i][i] for i in range(4)])
        examine([a[i][3-i] for i in range(4)])
    except FoundX:
        return "X won"
    except FoundO:
        return "O won"
    if full: return "Draw"
    return "Game has not completed"
    
tests = int(raw_input())
for test in range(tests):
    board = parse()
    result = solve(*board)
    print "Case #{0}: {1}".format(test+1, result)
