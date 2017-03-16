RIC = 'RICHARD'
GAB = 'GABRIEL'

T = int(raw_input())
for t in xrange(T):
    X, R, C = map(int, raw_input().split())
    if R > C:
        R, C = C, R  # R <= C

    assert 1 <= X <= 4
    assert 1 <= R <= 4
    assert 1 <= C <= 4

    def solve(R, C):
        if R * C % X != 0:
            return RIC

        if X <= 2:
            return GAB
        elif X == 3:
            return RIC if R == 1 else GAB
        elif X == 4:
            if R <= 2:
                return RIC
            elif R == 3:
                return GAB
            elif R == 4:
                return GAB

        assert False

    print 'Case #{}: {}'.format(t + 1, solve(R, C))
