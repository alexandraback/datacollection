#!/usr/bin/env python
import fileinput

def fashion(clothes):
    [a, b, c, k] = [int(x) for x in clothes.split(" ")]
    solutions = []
    ab = [[0 for i in range(b)] for j in range(a)]
    ac = [[0 for i in range(c)] for j in range(a)]
    bc = [[0 for i in range(c)] for j in range(b)]
    for x in range(a):
        for y in range(b):
            for z in range(c):
                if ab[x][y] < k and ac[x][z] < k and bc[y][z] < k:
                    ab[x][y] += 1
                    ac[x][z] += 1
                    bc[y][z] += 1
                    solutions.append(
                        str(x + 1) + " " + str(y + 1) + " " + str(z + 1))
                # else continue
    output = str(len(solutions)) + "\n" + "\n".join(solutions)
    return output

i = 0
for line in fileinput.input():
    line = line[0:-1] # strip carriage return
    if i == 0:
        i += 1
        continue
    print("Case #" + str(i) + ": " + str(fashion(line)))
    i += 1
