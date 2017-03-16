import sys

import numpy as np

import gurobipy

from gurobipy import GRB


def encode(s):

    a = np.zeros(26)
    for ch in s:
        a[ord(ch) - ord('A')] += 1
    return a


l = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
d = dict([(i, encode(l[i])) for i in range(10)])


def decode(s):
    counts = encode(s)

    res = []

    i = 0
    while np.any(counts > 0):
        while np.all(d[i] <= counts):
            counts -= d[i]
            res.append(i)
        i += 1

    return ''.join(map(str, res))

T = int(sys.stdin.next())

out = open('out', 'w')

for i in range(T):
    s = sys.stdin.next().strip()
    number = encode(s)

    m = gurobipy.Model()

    v = [m.addVar(vtype=GRB.INTEGER, lb=0) for i in range(10)]

    m.update()

    sums = [gurobipy.quicksum([v[i] * d[i][j] for i in range(10)]) for j in range(26)]

    for i in range(26):
        m.addConstr(sums[i] == number[i])

    m.optimize()

    out.write(''.join([str(i) * int(m.getVars()[i].x) for i in range(10)]) + '\n')

