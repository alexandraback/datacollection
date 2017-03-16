import math
import sys
import fractions

sys.setrecursionlimit(2 ** 20)

input = open('date.in', 'r')
output = open('date.out', 'w')

# 1 => 1
# i => 2
# j => 3
# k => 4

table = [
    [ ],
    [ -1, 1, 2, 3, 4 ],    # 1
    [ -1, 2, -1, 4, -3 ],  # i
    [ -1, 3, -4, -1, 2 ],  # j
    [ -1, 4, 3, -2, -1 ]   # k
]

def solve(S, X):
    pos = 0
    for c in range(2, 5):
        visited = set()
        s = 1
        x = 1
        while s == -1 or x != c:
            if X == 0:
                return False
            if pos == 0:
                if x * s in visited:
                    return False
                visited.add(x * s)
            j = 'x1ijk'.index(S[pos])
            x = table[x][j]
            if x < 0:
                x = -x
                s = -s
            pos += 1
            if pos == len(S):
                pos = 0
                X -= 1

    x = 1
    for i in range(len(S)):
        j = 'x1ijk'.index(S[i])
        x = table[x][j]
        if x < 0:
            x = -x
    cycleX = x

    s = 1
    x = 1
    # simulate [pos, N-1]
    if pos > 0:
        while pos < len(S):
            j = 'x1ijk'.index(S[pos])
            x = table[x][j]
            if x < 0:
                x = -x
                s = -s
            pos += 1
        X -= 1

    # X cycles left
    pairs = X / 2
    if cycleX != 1 and pairs % 2 == 1:
        s = -s
    X %= 2

    if X > 0:
        for i in range(len(S)):
            j = 'x1ijk'.index(S[i])
            x = table[x][j]
            if x < 0:
                x = -x
                s = -s

    return x == 1 and s == 1

T = int(input.readline())
for t in range(T):
    line = input.readline().strip().split(' ')
    N = int(line[0])
    X = int(line[1])
    S = input.readline().strip()
    ans = solve(S, X)
    output.write('Case #{}: {}\n'.format(t + 1, "YES" if ans else "NO"))
    print t

input.close()
output.close()