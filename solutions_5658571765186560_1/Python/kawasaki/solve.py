RIC = 'RICHARD'
GAB = 'GABRIEL'

T = int(raw_input())
for t in xrange(T):
    X, R, C = map(int, raw_input().split())
    if R > C:
        R, C = C, R  # R <= C

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
            return GAB
        elif X == 5:
            if R <= 2:
                return RIC
            elif R == 3:
                return RIC if C % 2 == 1 else GAB
            return GAB
        elif X == 6:
            if R <= 3:
                return RIC
            return GAB
        elif 7 <= X:
            return RIC
        assert False

    print 'Case #{}: {}'.format(t + 1, solve(R, C))
