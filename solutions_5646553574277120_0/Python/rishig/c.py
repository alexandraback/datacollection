import sys
from itertools import combinations

def hitvals(l, init = {0}):
    ans = init
    for val in l:
        app = set([x + val for x in ans])
        ans = ans | app
    return ans

def run(l1, Dl):
    c,d,v = [int(x) for x in l1.split()]
    D = [int(x) for x in Dl.split()]
    count = 0
    if v == 1:
        if 1 not in D:
            count += 1
        return count
    if 1 not in D:
        count += 1
        D.append(1)
    if 2 not in D:
        count += 1
        D.append(2)
    if v == 2:
        return count

    vset = frozenset(range(1,v+1))
    hv = hitvals(D)
    left = vset - hv

    if not left:
        return count

    for el in left:
        if not vset-hitvals([el], hv):
            return count + 1

    for ell in combinations(left, 2):
        if not vset-hitvals(ell, hv):
            return count + 2
    return count + 3

fin = open(sys.argv[1])
T = int(fin.readline().strip())
for i in range(1,T+1):
    line1 = fin.readline().strip()
    line2 = fin.readline().strip()
    ans = run(line1, line2)
    print('Case #%d: %s' % (i, ans))
