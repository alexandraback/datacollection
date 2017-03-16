E, R, N = 0, 0, 0
V = []
memo = {}

def solve(pos, enel):
    if pos == len(V):
        return 0
    if (pos, enel) in memo:
        return memo[(pos, enel)]
    ret = -1
    for i in range(enel+1):
        ret = max(ret, V[pos] * i + solve(pos + 1, min(E, enel - i + R)))
    memo[(pos, enel)] = ret
    return ret

for i in range(int(input())):
    E, R, N = list(map(int, input().split(' ')))
    V = []
    memo = {}
    for j in input().split(' '):
        V.append(int(j))
    print('Case #{}: {}'.format(i+1, solve(0, E)))
