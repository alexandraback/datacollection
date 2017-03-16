import jam

import sys
sys.setrecursionlimit(10000)

def result(s):
    if len(s) == 0:
        return ""
    largest = None
    largestOrd = 0
    largestIndex = -1
    for i in range(len(s)):
        c = s[i]
        if ord(c) >= largestOrd:
            largest = c
            largestOrd = ord(c)
            largestIndex = i
    return largest + result(s[:largestIndex]) + s[largestIndex+1:]

def solve(case):
    S = case.readLine()
    return result(S)

jam.run("A-large.in", solve)
