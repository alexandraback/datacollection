#benoni.boy
#Google Code Jam
#13 April 2013
import sys
import random

sys.stdin = open('C:\GCJ\in.txt')
sys.stdout = open('C:\GCJ\out.txt', 'w')

input()
input()
#Already know input parameters

threeSets = []
for n1 in range(4):
    for n2 in range(4):
        for n3 in range(4):
            threeSets.append([n1 + 2, n2 + 2, n3 + 2])

prods = {}

for i in [2, 3, 4, 5]:
    for n in threeSets:
        for j in range(8):
            p = 1
            if (j % 2): p *= n[0]
            j //= 2
            if (j % 2): p *= n[1]
            j //= 2
            if (j % 2): p *= n[2]
            if not (p in prods):
                prods[p] = [n]
            else:
                prods[p].append(n)

print('Case #1:')
for i in range(100):
    p = list(map(int, input().split()))
    pos = threeSets
    for j in p:
        pos = [k for k in pos if k in prods[j]]
    print(''.join([str(l) for l in random.sample(pos, 1)[0]]))

sys.stdin.close()
sys.stdout.close()
