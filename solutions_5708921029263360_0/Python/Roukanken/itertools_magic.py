import itertools
from collections import defaultdict

def work():
    J, P, S, K = [int(x) for x in input().strip().split()]

    JP, PS, JS = defaultdict(int), defaultdict(int), defaultdict(int)

    res = []

    for j, p, s in itertools.product(range(J), range(P), range(S)):
        if JP[j, p] >= K: continue
        if PS[p, s] >= K: continue
        if JS[j, s] >= K: continue

        JP[j, p] += 1
        PS[p, s] += 1
        JS[j, s] += 1

        res += [str(j+1) + " " + str(p+1) + " " + str(s+1)]

    return str(len(res)) + "\n" + "\n".join(res)

T = int(input())
for test_case in range(T):
    print ("Case #{}:".format(test_case+1), work())