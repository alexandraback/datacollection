from itertools import count
from random import randint
from sys import stdout

namein = 'B-small-attempt0.in'
nameout = 'small.out'

def solve():
    b, m = [int(s) for s in fin.readline().split()]
    a = [[0 for _ in range(b)] for _ in range(b)]
    for i in range(b):
        for j in range(i+1, b-1):
            a[i][j] = 1
    if 2**(b-2) < m:
        return 'IMPOSSIBLE'
    elif 2**(b-2) == m:
        for i in range(b-1):
            a[i][b-1] = 1
    else:
        for i in range(1, b-1):
            if ((2**(i-1))&m) != 0:
                a[i][b-1] = 1
    ret = ['POSSIBLE']
    for i in range(b):
        ret.append(''.join(str(ai) for ai in a[i]))
    return '\n'.join(ret)

fin = open(namein, 'r')
fout = open(nameout, 'w')
# fout = stdout
T = int(fin.readline())
for i in range(1, T+1):
    print('Case #{}: {}'.format(i, solve()), file=fout)
