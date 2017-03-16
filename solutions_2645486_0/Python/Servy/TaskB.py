'''
Created on 27.04.2013

@author: Servy
'''
import sys

tests = int(sys.stdin.readline())

def getPoints(i, c, e, r, v):
    if i >= len(v):
        return 0
    if c > e:
        c = e
    if c < 0:
        c = 0
    global answers
    if answers[i][c] >= 0:
        return answers[i][c]
    else:
        bestSpend = 0
        bestPoints = 0
        for spend in range(c+1):
            points = getPoints(i+1, c-spend+r, e, r, v) + v[i] * spend
            if points > bestPoints:
                bestPoints = points
                bestSpend = spend
        answers[i][c] = getPoints(i+1, c-bestSpend+r, e, r, v) + v[i] * bestSpend
        return answers[i][c]    

def solve(e, r, v):
    return getPoints(0, e, e, r, v)
    

for test in range(tests):
    (e, r, n) = map(int, sys.stdin.readline().split())
    v = list(map(int, sys.stdin.readline().split()))
    answers = []
    for i in range(n):
        answers.append([-1 for i in range(6)])
    print("Case #%d: %d" % (test+1, solve(e, r, v)))
       
        