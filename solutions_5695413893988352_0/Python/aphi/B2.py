from sys import stdin, stdout
from itertools import product
from collections import defaultdict

q = "?"


def solve(A, B):
    n = len(A)
    #print A, B
    bestA = 99999
    bestB = 0


    for p in product(range(10), repeat=A.count(q) + B.count(q)):


        a = ""
        pi = 0
        for i in A:
            if i == q:
                a += str(p[pi])
                pi += 1
            else:
                a += i

        b = ""
        for i in B:
            if i == q:
                b += str(p[pi])
                pi += 1
            else:
                b += i

        a, b = int(a), int(b)

        #print a, b

        if abs(a-b) <= abs(bestA - bestB):
            if abs(a-b) < abs(bestA - bestB):
                bestA, bestB = a, b
                continue
            if a <= bestA:
                if a < bestA:
                    bestA, bestB = a, b
                    continue
                else:
                    if b < bestB:
                        bestA, bestB = a, b
                        continue


    return str(bestA).zfill(n) + " " + str(bestB).zfill(n)



T = int(stdin.readline())

for t in range(T):
    A, B = stdin.readline().strip().split()

    result = solve(A, B)

    stdout.write("Case #%d: %s\n"%(t+1, result))