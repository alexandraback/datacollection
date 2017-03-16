RICH = 'RICHARD'
GAB = 'GABRIEL'

DD = {}
DD[(3, 1, 3,)] = RICH
DD[(3, 2, 3,)] = GAB
DD[(3, 3, 3,)] = GAB
DD[(3, 3, 4,)] = GAB
DD[(4, 1, 4,)] = RICH
DD[(4, 2, 4,)] = RICH
DD[(4, 3, 4,)] = GAB
DD[(4, 4, 4,)] = GAB

def solve(X, R, C):
    if R > C:
        return solve(X, C, R)

    assert R <= C

    if X >= 7:
        return RICH

    if C*R % X != 0:
        return RICH

    if X <= 2:
        return GAB

    M = max([C, R])
    m = min([C, R])

    if X > M:
        return RICH

    return DD[(X, R, C)]

# for X in xrange(1, 5):
#     for R in xrange(1, 5):
#         for C in xrange(1, 5):
#             print X, R, C
#             print solve(X, R, C)

T = int(raw_input())

for i in xrange(T):
    X, R, C = [int(x) for x in raw_input().split()]

    print 'Case #%d: %s' % (i + 1, solve(X, R, C))
