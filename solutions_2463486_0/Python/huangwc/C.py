from sys import stdin, stdout
from math import sqrt

stdin = open('C-small-attempt0.in', 'r')
stdout = open('C-small.out', 'w')

def is_pal(x):
    return str(x) == str(x)[::-1]

T = int(stdin.readline().strip())

for t in range(1, T+1):

    (A, B) = [int(x) for x in stdin.readline().strip().split()]

    x = int(sqrt(A-1))+1
    cnt = 0

    while x * x <= B:
        cnt += 1 if is_pal(x) and is_pal(x * x) else 0
        x += 1

    stdout.write('Case #%d: %d\n' % (t, cnt))

stdin.close()
stdout.close()
