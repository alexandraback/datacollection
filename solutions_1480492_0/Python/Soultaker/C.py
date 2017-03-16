#!/usr/bin/env python3

from fractions import Fraction
from multiprocessing import Pool
from sys import stdin

def readCase():
    N = int(stdin.readline())
    C, S, P = [], [], []
    for n in range(N):
        c,s,p = stdin.readline().split()
        C.append("LR".index(c))
        S.append(int(s))
        P.append(int(p))
    return (N,C,S,P)

def solveCase(case):
    N,C,S,P = case

    # Calculcate when pairs of cars pass each other:
    passing = []  # i,j,time
    for i in range(N):
        for j in range(N):
            if P[i] + 5 <= P[j] and S[i] > S[j]:
                t = Fraction(P[j] - P[i] - 5, S[i] - S[j])
                if t >= 0:
                    passing.append((i, j, t))

    def position(i, t):
        'Returns the position of the i-th car at time t.'
        return P[i] + t*S[i]

    def blocked(i, t):
        'Returns whether the i-th car is blocked at time t (ignoring car k).'
        x = position(i, t)
        for j in range(N):
            if j != i:
                y = position(j, t)
                if abs(x - y) < 5:
                    return True
        return False

    # Order passings by time:
    passing.sort(key=lambda ijt: ijt[2])

    # Try all possible ways of passing:
    last_time = -1
    fixed = {}
    answer = 0
    for mask in range(1<<len(passing)):
        lane = [ C[i] for i in range(N) ]
        pos  = [ Fraction(P[i]) for i in range(N) ]

        for i,j,t in passing:
            if t != last_time:
                last_time = t
                fixed = {}

            if lane[i] != (mask&1):
                if blocked(i, t): break
                lane[i] = mask&1
            if i in fixed and fixed[i] != lane[i]: break
            fixed[i] = lane[i]

            if lane[j] != (~mask&1):
                if blocked(j, t): break
                lane[j] = ~mask&1
            if j in fixed and fixed[j] != lane[j]: break
            fixed[j] = lane[j]

            mask >>= 1
        else:
            return "Possible"

        answer = max(answer, t)


    return "%.9f"%float(answer)

if __name__ == '__main__':
    cases = int(stdin.readline())
    answers = Pool(8).map(solveCase, (readCase() for _ in range(cases)))
    for case, answer in enumerate(answers, 1):
        print('Case #%d:'%case, answer)
