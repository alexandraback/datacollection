from itertools import count
from random import randint
from sys import stdout

namein = 'A-large.in'
nameout = 'A-large.out'

def solve(n):
    n = int(n)
    if n == 0:
        return 'INSOMNIA'
    flags = [False for i in range(10)]
    for i in count(1):
        ni = n*i
        while ni != 0:
            flags[ni%10] = True
            ni //= 10
        if all(flags):
            return n*i

fin = open(namein, 'r')
fout = open(nameout, 'w')
# fout = stdout
T = int(fin.readline())
for i in range(1, T+1):
    print('Case #{}: {}'.format(i, solve(fin.readline())), file=fout)
