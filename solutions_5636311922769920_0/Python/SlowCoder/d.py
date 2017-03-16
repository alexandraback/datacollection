
import math


def solve(K, C, S):
    result = []

    for p in range(0, K):
        idx = 0
        for exp in range(0, C):
            idx += p * (K ** exp)

        result.append(idx + 1)

    return result


f = open('in.in', 'r')
T = int(f.readline())

for t in range(1, T + 1):
    line = f.readline()
    line_exploded = line.split(' ')
    K = int(line_exploded[0])
    C = int(line_exploded[1])
    S = int(line_exploded[2])

    result = solve(K, C, S)

    print('Case #' + str(t) + ': ' + ' '.join([str(x) for x in result]))
