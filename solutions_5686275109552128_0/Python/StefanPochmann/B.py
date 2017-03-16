#f = open('B.in')
#def input():
#    return next(f)

memo = {}
d = 0
def steps(P):
    P = tuple(sorted(p for p in P if p))
    global d
    #print('  ' * d, P)
    if not P:
        return 0
    if P[-1] == 1:
        return 1
    d += 1
    if P not in memo:
        next1 = (p - 1 for p in P if p)
        next2 = P[:-1] + (P[-1] // 2, (P[-1] + 1) // 2)
        memo[P] = 1 + min(steps(next1), steps(next2))
    d -= 1
    return memo[P]

T = int(input())
for x in range(1, T + 1):
    input()
    P = map(int, input().split())
    print('Case #{}: {}'.format(x, steps(P)))
