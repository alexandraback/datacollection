#!/usr/bin/env python

SOLVED = 2 ** 10 - 1 #0b1111111111
NO_ANSWER = 'INSOMNIA'

def solve(N):
    if N == 0:
        return NO_ANSWER
    bitMap = 0
    i = 1
    while(True):
        digits = map(int, str(i * N))
        for digit in digits:
            bitMap |= 2 ** digit
        if bitMap == SOLVED:
            return i * N
        i += 1

T = int(raw_input().strip())
for testCaseNo in range(T):
    N = int(raw_input().strip())
    print 'Case #' + str(testCaseNo + 1) + ':',
    print solve(N)