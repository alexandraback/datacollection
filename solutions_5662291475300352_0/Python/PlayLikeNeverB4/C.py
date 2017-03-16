import math
import sys
import fractions

sys.setrecursionlimit(2 ** 20)

input = open('date.in', 'r')
output = open('date.out', 'w')

MAX = 12
D = [ 0 for i in range(MAX) ]
S = [ 0 for i in range(MAX) ]
K = 0

def solve():
    assert K <= 2
    if K == 1:
        return 0
    if S[0] == S[1]:
        return 0

    for i in range(K):
        for j in range(i + 1, K):
            if D[i] > D[j]:
                D[i], D[j] = D[j], D[i]
                S[i], S[j] = S[j], S[i]

    ans = 1
    if S[0] > S[1]:
        # 0 slower than 1
        if S[0] * (360 - D[0]) < S[1] * (720 - D[1]):
            ans = 0
    else:
        # 0 faster than 1
        if S[1] * (360 - D[1]) < S[0] * (720 - D[0]):
            ans = 0

    return ans

T = int(input.readline())
for t in range(T):
    N = int(input.readline().strip())
    K = 0
    for i in range(N):
        line = input.readline().strip().split(' ')
        d = int(line[0])
        cnt = int(line[1])
        s = int(line[2])
        for j in range(cnt):
            D[K] = d
            S[K] = s + j
            K += 1
    ans = solve()
    output.write('Case #{}: {}\n'.format(t + 1, ans))
    print t

input.close()
output.close()