import math
import sys
import fractions
from collections import deque

sys.setrecursionlimit(2 ** 20)

input = open('date.in', 'r')
output = open('date.out', 'w')

def getRev(x):
    A = str(x)
    A = A[::-1]
    ret = int(A)
    return ret

MAX = 10 ** 6 + 2
dp = [ MAX for i in range(MAX) ]
v = [ False for i in range(MAX) ]

Q = deque()
Q.append(1)
dp[1] = 1
v[1] = True
while len(Q) > 0:
    i = Q.popleft()
    if i + 1 < MAX and dp[i] + 1 < dp[i + 1]:
        dp[i + 1] = dp[i] + 1
        if not v[i + 1]:
            v[i + 1] = True
            Q.append(i + 1)
    rev = getRev(i)
    if rev < MAX and dp[i] + 1 < dp[rev]:
        dp[rev] = dp[i] + 1
        if not v[rev]:
            v[rev] = True
            Q.append(rev)

T = int(input.readline())
for t in range(T):
    N = int(input.readline())
    ans = dp[N]
    output.write('Case #{}: {}\n'.format(t + 1, ans))
    print t

input.close()
output.close()