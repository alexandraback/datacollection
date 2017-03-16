import numpy as np
import sys
a=open(sys.argv[-1]).readlines()[1:]
problems = []
for i in range(len(a)):
    if len(a[i].split()) == 1:
        problem = a[i + 1 : i + int(a[i]) * 2]
        problem = [j.split() for j in problem]
        problems.append(problem)


def solve(problem):
    a = np.zeros(2501)
    for hlist in problem:
        for height in hlist:
            a[int(height)] += 1
    b = ''
    for i in range(len(a)):
        if a[i] % 2 == 1:
            b += str(i) + ' '
    return b

for i in range(len(problems)):
    print 'Case #' + str(i + 1) + ': ' + solve(problems[i])
