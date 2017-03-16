#!/usr/bin/env python
# Python 3

import platform
assert platform.python_version_tuple()[0] == '3'
import copy

cs = []
js = []

answers = []  # not proud of this

def solution(c, j):
    global answers

    permute(c)
    cs = copy.deepcopy(answers)
    answers = []

    permute(j)
    js = copy.deepcopy(answers)
    answers = []

    solution_c = cs[0]
    solution_j = js[0]

    for c in cs:
        for j in js:
            cint = int(c)
            jint = int(j)
            scint = int(solution_c)
            sjint = int(solution_j)
            if abs(cint - jint) <= abs(scint - sjint):

                if abs(cint - jint) < abs(scint - sjint):
                    solution_c = c
                    solution_j = j
                else:
                    if cint <= scint:
                        if cint < scint:
                            solution_c = c
                            solution_j = j
                        else:
                            if jint < sjint:
                                solution_c = c
                                solution_j = j

    return solution_c + ' ' + solution_j

def permute(qscore):
    global answers

    qpos = qscore.find('?')
    if qpos == -1:
        answers.append(qscore)
    else:
        for x in range(10):
            permute(qscore[:qpos] + str(x) + qscore[qpos + 1:])


# Taken from https://code.google.com/codejam/tutorials.html
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# Customize the lines in the for loop to suit the input format
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    c, j = [s for s in input().split(" ")]
    print("Case #{}: {}".format(i, solution(c, j)))
