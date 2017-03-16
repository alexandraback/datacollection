#!/usr/bin/env python

HAPPY_FACE = '+'
BLANK = '-'

def solvePancakes(pancakes):
    changes = 0
    for i in range(len(pancakes) - 1): #everything except the last
        if pancakes[i] != pancakes[i + 1]:
            changes += 1
    if ((pancakes[0] == HAPPY_FACE and changes % 2 == 0) or
            (pancakes[0] == BLANK and changes % 2 == 1)):
        return changes
    else:
        return changes + 1 #extra flip to change sign

T = int(raw_input().strip())
for testCaseNo in range(T):
    pancakes = raw_input().strip()
    print 'Case #' + str(testCaseNo + 1) + ':',
    print solvePancakes(pancakes)