from itertools import *

#f = open('C.in')
#def input():
#    return next(f)

I, J, K = 2, 3, 4
table = [[1,  I,  J,  K],
         [I, -1,  K, -J],
         [J, -K, -1,  I],
         [K,  J, -I, -1]]

def sign(a):
    return 1 if a > 0 else -1

def mul(a, b):
    return sign(a) * sign(b) * table[abs(a) - 1][abs(b) - 1]
    
def eval(s):
    res = 1
    for q in s:
        res = mul(res, '.1ijk'.index(q))
    return res

def possible(X, S):
    if X > 24:
        X = 12 + X % 12
    S *= X
    if eval(S) != eval('ijk'):
        return 'NO'

    S = list(map('.1ijk'.index, S))

    # Find the length of the shortest prefix worth i
    value = 1
    i_len = 0
    for q in S:
        value = mul(value, q)
        i_len += 1
        if value == I:
            break
    if value != I:
        return 'NO'

    # Find the length of the shortest prefix worth k
    value = 1
    k_len = 0
    for q in reversed(S):
        value = mul(q, value)
        k_len += 1
        if value == K:
            break
    if value != K:
        return 'NO'

    return 'YES' if i_len + k_len < len(S) else 'NO'

T = int(input())
for x in range(1, T + 1):
    X = int(input().split()[1])
    S = input().strip()
    print('Case #{}: {}'.format(x, possible(X, S)))
