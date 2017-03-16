import numpy as np
import sys
a=open(sys.argv[-1]).readlines()[2::2]
problems = [j.split() for j in a]


def solve(problem):
    problem = [int(i) - 1 for i in problem]
    counts = np.zeros(len(problem))
    mutual = {}
    for i in range(len(problem)):
        arr = []
        done = False
        k = i
        m = None
        while not done:
            arr.append(k)
            k = problem[k]
            if problem[k] == arr[-1]:
                arr.append(k)
                if (problem[k], k) not in mutual or mutual[(problem[k], k)] < len(arr):
                    mutual[(problem[k], k)] = len(arr)
                m = (k, problem[k])
                done = True
            if k in arr:
                done = True

        if m in mutual.keys():
            counts[i] = len(arr) + mutual[m] - 2
        else:
            counts[i] = len(arr)
    return int(max(counts))

for i in range(len(problems)):
    print 'Case #' + str(i + 1) + ': ' + str(solve(problems[i]))
