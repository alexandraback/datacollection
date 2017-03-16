from copy import copy
from itertools import count, product
from random import randint
from sys import stdout

namein = 'C-small-attempt0.in'
nameout = 'small.out'

def solve():
    J, P, S, K = [int(s) for s in fin.readline().split()]
    m1 = {}
    rm1 = {}
    m2 = {}
    m3 = {}
    m4 = {}
    for i, p in enumerate(product(range(J), range(P), range(S))):
        m1[p] = i
        rm1[i] = p
    for i, p in enumerate(product(range(J), range(P))):
        m2[p] = i
    for i, p in enumerate(product(range(J), range(S))):
        m3[p] = i
    for i, p in enumerate(product(range(P), range(S))):
        m4[p] = i
    a = [0 for _ in range(J*P*S)]
    for p, i in m1.items():
        a[i] = (m2[p[0], p[1]], m3[p[0], p[2]], m4[p[1], p[2]])
    used = [[0 for _ in m2], [0 for _ in m3], [0 for _ in m4]]
    ans = []
    def dfs(used, now, nowi):
        nonlocal ans
        if len(now) > len(ans):
            ans = copy(now)
        elif len(now)+len(a)-nowi <= len(ans):
            return
        for i in range(nowi, len(a)):
            for j in range(3):
                if used[j][a[i][j]] >= K:
                    break
            else:
                for j in range(3):
                    used[j][a[i][j]] += 1
                now.append(i)
                dfs(used, now, i+1)
                for j in range(3):
                    used[j][a[i][j]] -= 1
                now.pop()
    dfs(used, [], 0)
    ret = [str(len(ans))]
    for i in ans:
        ret.append(' '.join(str(aii+1) for aii in rm1[i]))
    return '\n'.join(ret)

fin = open(namein, 'r')
fout = open(nameout, 'w')
# fout = stdout
T = int(fin.readline())
for i in range(1, T+1):
    print('Case #{}: {}'.format(i, solve()), file=fout)
