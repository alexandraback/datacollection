import math
import sys
import fractions

sys.setrecursionlimit(2 ** 20)

input = open('date.in', 'r')
output = open('date.out', 'w')

def solve(S):
    ret = 0
    sum = 0
    for i in range(len(S)):
        extra = max(0, i - sum)
        ret += extra
        sum += extra
        sum += int(S[i])
    return ret

T = int(input.readline())
for t in range(T):
    line = input.readline().strip().split(' ')
    S = line[1]
    ans = solve(S)
    output.write('Case #{}: {}\n'.format(t + 1, ans))
    print t

input.close()
output.close()