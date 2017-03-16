#!/usr/bin/python
#name = 'B.test'
name = 'B-small-attempt0.in'
#name = 'B-large.in'
from pulp import * #Note: pulp is a free and open source LP library using GLPK, free and open source


def make():
    E,R,N = [int(i) for i in FILE.readline().split(' ')]
    V = [int(i) for i in FILE.readline().split(' ')]
    var_names = [str(i) for i in range(1,N+1)]

    cost = dict(zip(var_names, V))
    #print(cost)
    energy_model = LpProblem('Energy Problem', LpMaximize)
    x = LpVariable.dict('x_%s', var_names, lowBound=0)
    I = LpVariable.dict('I_%s', var_names, lowBound=0, upBound=E)
    energy_model += lpSum( [cost[i] * x[i] for i in var_names] )

    energy_model += I['1'] == E
    for i in var_names:
        energy_model += I[i] - x[i] >= 0
    for j in range(1,N):
        energy_model += I[str(j+1)] - I[(str(j))] + x[str(j)] <= R

    energy_model.solve(GLPK(msg = 0))
    return(str(int(value(energy_model.objective))))













FILE = open(name)
T = int(FILE.readline())

for i in range(1, T+1):
    print("Case #" + str(i) + ": " + str(make()))