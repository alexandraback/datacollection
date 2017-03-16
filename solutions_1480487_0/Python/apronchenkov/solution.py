import sys

def CheckIY(i, y, J):
    Y = 1.0 - y
    X = sum(J)
    Si = J[i] + y * X
    for j in xrange(len(J)):
        if i == j:
            continue
        Y = Y - max(0.0, (Si - J[j]) / X)
    return Y < 0


def SolveI(i, J):
    l = 0.0
    r = 1.0
    while r - l > 1e-10:
        c = (l + r) / 2.0
        if CheckIY(i, c, J):
            r = c
        else:
            l = c
    return l

def Solve(J):
    return [ 100.0 * SolveI(i, J) for i in xrange(len(J)) ]

numberOfCases = int(sys.stdin.readline())
for case in xrange(numberOfCases):
    token = map(int, sys.stdin.readline().split())

    result = "Case #%d:" % (case + 1)
    for y in Solve(token[1:1 + token[0]]):
        result += " %.7f" % y
    print result
