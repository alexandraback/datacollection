#!/usr/bin/python

def sufficient(score, P):
    return score >= P + 2 * max((P - 1), 0)

def surprising(score, P):
    return score >= P + 2 * max((P - 2), 0)

T = int(raw_input())
for i in range(T):
    line = map(int, raw_input().split())
    N = line[0]
    S = line[1]
    p = line[2]
    result = 0
    for j in range(3, N+3):
        if sufficient(line[j], p):
            result += 1
        elif S > 0 and surprising(line[j], p):
            result += 1
            S -= 1
    print 'Case #' + str(i + 1) + ': ' + str(result)
