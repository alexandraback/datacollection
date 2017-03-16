import sys

import gurobipy

from gurobipy import GRB


T = int(sys.stdin.next())

out = open('out', 'w')

c = 0
for i in range(T):
    s1, s2 = sys.stdin.next().strip().split(' ')

    n = len(s1)

    m = gurobipy.Model()

    v1 = [m.addVar(vtype=GRB.INTEGER, lb=0, ub=9) for i in range(n)]
    v2 = [m.addVar(vtype=GRB.INTEGER, lb=0, ub=9) for i in range(n)]
    dummy = m.addVar()
    m.update()

    score1 = gurobipy.quicksum([v1[n - 1 - i] * (10 ** i) for i in range(n)])
    score2 = gurobipy.quicksum([v2[n - 1 - i] * (10 ** i) for i in range(n)])

    for i in range(n):
        if s1[i] != '?':
            m.addConstr(v1[i] == int(s1[i]))
    for i in range(n):
        if s2[i] != '?':
            m.addConstr(v2[i] == int(s2[i]))

    m.addConstr(dummy >= (score1 - score2))
    m.addConstr(dummy >= (score2 - score1))

    m.setObjective(dummy)

    m.setParam('OutputFlag', False)
    m.optimize()

    objective = int(dummy.x)
    m.addConstr(dummy <= objective)

    sol1 = ''.join([str(int(m.getVars()[i].x)) for i in range(n)])
    sol2 = ''.join([str(int(m.getVars()[n + i].x)) for i in range(n)])

    while 1:
        cc = m.addConstr(score1 <= (int(sol1) - 1))

        m.optimize()

        if m.Status == 2:
            sol1 = ''.join([str(int(m.getVars()[i].x)) for i in range(n)])
            sol2 = ''.join([str(int(m.getVars()[n + i].x)) for i in range(n)])
        else:
            m.remove(cc)
            m.update()
            break

    while 1:
        cc = m.addConstr(score2 <= (int(sol2) - 1))

        m.optimize()

        if m.Status == 2:
            sol1 = ''.join([str(int(m.getVars()[i].x)) for i in range(n)])
            sol2 = ''.join([str(int(m.getVars()[n + i].x)) for i in range(n)])
        else:
            m.remove(cc)
            m.update()
            break

    print('Case #%i: ' % (c + 1) + '%s %s' % (sol1, sol2))

    c += 1
