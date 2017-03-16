#!/usr/bin/python3
from math import inf

def matches(a, val):
    for x in zip(a, val):
        if x[0] != '?' and x[0] != x[1]:
            return False
    return True

for t in range(int(input())):
    best_diff = inf
    best_i = 0
    best_j = 0
    a, b = input().split()

    for i in range(0, 10**len(a)):
        if not matches(a, '0' * (len(a) - len(str(i))) + str(i)):
            continue

        for j in range(0, 10**len(b)):
            diff = abs(i-j)

            if diff > best_diff:
                continue

            if not matches(b, '0' * (len(b) - len(str(j))) + str(j)):
                continue


            if diff < best_diff:
                best_diff = diff
                best_i = i
                best_j = j

            elif diff == best_diff:
                if i < best_i:
                    best_i = i
                    best_j = j
                elif i == best_i:
                    if j < best_j:
                        best_j = j

    print("Case #%i: %s %s" % (t+1, '0'*(len(a)-len(str(best_i)))+str(best_i), \
                                    '0'*(len(b)-len(str(best_j)))+str(best_j)))


