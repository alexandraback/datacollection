import math
import sys
import fractions

sys.setrecursionlimit(2 ** 20)

input = open('date.in', 'r')
output = open('date.out', 'w')

T = int(input.readline())
for t in range(T):
    N = int(input.readline())
    P = [ 0 for i in range(N) ]
    line = input.readline().strip().split(' ')
    for i in range(N):
        P[i] = int(line[i])
    ans = 1000
    for max in range(1, 1001):
        total = 0
        for i in range(N):
            total += (P[i] + max - 1) / max - 1
        ans = min(ans, total + max)
    output.write('Case #{}: {}\n'.format(t + 1, ans))
    print t

input.close()
output.close()