# Solution to "Close Match" for Google Code Jam 2016
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys
from collections import Counter

def cases(inputFile):
    with open(inputFile, 'r') as f:
        numCases = int(f.readline())
        for _ in range(numCases):
            yield f.readline().split(' ')

options = []
best = -1

def difference(scores):
    return abs(int(scores[0]) - int(scores[1]))

def replace(string, pos, replacement):
    return string[:pos] + replacement + string[pos+1:]

def update(scores):
    global best, options
    d = difference(scores)
    if best == -1 or d < best:
        best = d
        options = [scores]
    elif d == best:
        options.append(scores)

def innerSolve(scores, p, bigger):
    if p >= len(scores[0]):
        update(scores)
        return
    if scores[0][p] != '?' and scores[1][p] != '?':
        if bigger == -1:
            if int(scores[0][p]) > int(scores[1][p]):
                bigger = 0
            elif int(scores[1][p]) > int(scores[0][p]):
                bigger = 1
        return innerSolve(scores, p+1, bigger)
    if bigger != -1:
        for team in (0, 1):
            if scores[team][p] == '?':
                replacement = '0' if bigger == team else '9'
                scores[team] = replace(scores[team], p, replacement)
        return innerSolve(scores, p+1, bigger)
    if scores[0][p] == '?' and scores[1][p] == '?':
        innerSolve([replace(scores[0], p, '1'), replace(scores[1], p, '0')], p+1, 0)
        innerSolve([replace(scores[0], p, '0'), replace(scores[1], p, '1')], p+1, 1)
        innerSolve([replace(scores[0], p, '0'), replace(scores[1], p, '0')], p+1, -1)
        return
    if scores[0][p] == '?':
        target = int(scores[1][p])
        innerSolve([replace(scores[0], p, str(target)), scores[1]], p+1, -1)
        if target != 0:
            innerSolve([replace(scores[0], p, str(target-1)), scores[1]], p+1, 1)
        if target != 9:
            innerSolve([replace(scores[0], p, str(target+1)), scores[1]], p+1, 0)
        return
    if scores[1][p] == '?':
        target = int(scores[0][p])
        innerSolve([scores[0], replace(scores[1], p, str(target))], p+1, -1)
        if target != 0:
            innerSolve([scores[0], replace(scores[1], p, str(target-1))], p+1, 0)
        if target != 9:
            innerSolve([scores[0], replace(scores[1], p, str(target+1))], p+1, 1)
        return

def basicInner(scores,p):
    if p >= len(scores[0]):
        update(scores)
        return
    if scores[0][p] == '?':
        for r in range(10):
            basicInner([replace(scores[0], p, str(r)), scores[1]], p)
        return
    if scores[1][p] == '?':
        for r in range(10):
            basicInner([scores[0], replace(scores[1], p, str(r))], p)
        return
    basicInner(scores, p+1)

def solve(scores):
    global best, options
    best = -1
    options = []
    innerSolve(scores, 0, -1)
    options.sort()
    result = options[0]
    #best = -1
    #options = []
    #basicInner(scores, 0)
    #options.sort()
    #if result != options[0]:
    #    print scores, result, options[0]
    return ' '.join(result)

with open(sys.argv[2], 'w') as f:
    for num, scores in enumerate(cases(sys.argv[1])):
        f.write("Case #%d: %s"%(num+1, solve(scores)))
