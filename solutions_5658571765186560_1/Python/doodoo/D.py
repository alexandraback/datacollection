RICH = 'RICHARD'
GAB = 'GABRIEL'

DD = {}
DD[(5, 3, 5,)] = GAB
DD[(5, 4, 5,)] = GAB
DD[(5, 5, 5,)] = GAB
DD[(5, 5, 6,)] = GAB
DD[(5, 5, 7,)] = GAB
DD[(6, 3, 6,)] = RICH
DD[(6, 4, 6,)] = GAB
DD[(6, 5, 6,)] = GAB
DD[(6, 6, 6,)] = GAB
DD[(6, 6, 7,)] = GAB

def solve_inter(X, R, C):
    if R > C:
        return solve_inter(X, C, R)
    assert R <= C

    if R > 7:
        return solve_inter(X, 7, 7)
    if C > 7:
        return solve_inter(X, R, R)

    if X <= 2:
        return GAB

    M = max([C, R])
    m = min([C, R])

    if X > M:
        return RICH

    if X > 2*R:
        return RICH

    if X == 3 and R > 1:
        return GAB

    if X == 4 and R == 2: # tetris brick
        return RICH

    if X == 4 and R > 2:
        return GAB

    if X < R:
        return GAB

    return DD[(X, R, C)]

def solve(X, R, C):
    if X >= 7:
        return RICH

    if C*R % X != 0:
        return RICH

    return solve_inter(X, R, C)

# F = 30
# for X in xrange(1, F):
#     for R in xrange(1, F):
#         for C in xrange(1, F):
#             print X, R, C
#             print solve(X, R, C)

T = int(raw_input())

for i in xrange(T):
    X, R, C = [int(x) for x in raw_input().split()]

    print 'Case #%d: %s' % (i + 1, solve(X, R, C))
