from sys import stdin, stdout
import itertools
from collections import defaultdict
import coinor.pulp as pulp

# I'm way too reliant on integer programming.

def solve(topics):
    p = pulp.LpProblem("", pulp.LpMinimize)

    topicVars = []

    fWordVars = defaultdict(list)
    sWordVars = defaultdict(list)
    for i, t in enumerate(topics):
        fWordVars[t[0]].append(i)
        sWordVars[t[1]].append(i)

        topicVars.append( pulp.LpVariable("topic %d"%i, cat=pulp.LpBinary) )

    p += pulp.lpSum(topicVars)

    for word in fWordVars:
        p += pulp.lpSum(topicVars[i] for i in fWordVars[word]) >= 1, ""

    for word in sWordVars:
        p += pulp.lpSum(topicVars[i] for i in sWordVars[word]) >= 1, ""

    p.solve()

    return len(topics) - int(pulp.value(p.objective))



T = int(stdin.readline())

for t in range(T):
    N = int(stdin.readline())

    topics = []
    for _ in range(N):
        topics.append( stdin.readline().strip().split() )

    result = solve(topics)

    stdout.write("Case #%d: %s\n"%(t+1, result))