# -*- coding: utf-8 -*- 
import os, sys, copy, time, itertools

def solve(linea, lineb):
    typed, all = map(int, linea.split())
    p = map(float, lineb.split())

    # i번째 타이핑까지 모두 정확했을 확률
    correct_p = []
    for x in p:
        if correct_p:
            correct_p.append(correct_p[-1] * x)
        else:
            correct_p.append(x)

    expects = []

    # keep typing
    remain = all - typed
    expects.append(correct_p[-1] * (remain + 1) + (1.0 - correct_p[-1]) * (remain + 1 + all + 1))

    # backspaces
    backspaces = []
    for i in xrange(1, typed):
        backspace = i
        # backspace*i, retype*i, enter*1
        p1, p2 = correct_p[-1 - i], (1.0 - correct_p[-1 - i])
        backspaces.append(p1 * (i + i + remain + 1) + p2 * (i + i + remain + 1 + all + 1))
    expects += backspaces

    # enter
    if remain != 0:
        expects.append(2 + all)

    return min(expects)

lines = sys.stdin.read().split('\n')
lines.pop()
lines.pop(0)

case = 0
while lines:
    case += 1
    linea = lines.pop(0)
    lineb = lines.pop(0)

    print 'Case #%d: %s' % (case, solve(linea, lineb))
