def solve(X, R, C):
    """ solve the problem """

    if X == 1:
        return True
    if X == 2:
        if (R*C) % 2 == 0: return True
    if X == 3:
        if (R*C) % 3 != 0: return False
        if max(R, C) >= X and min(R, C) >= X-1: return True
    if X == 4:
        if (R*C) % 4 != 0: return False
        if max(R, C) >= X and min(R, C) >= X-1: return True
    if X == 5:
        if (R*C) % 5 != 0: return False
        if max(R, C) >= X and min(R, C) >= X-1: return True
    if X == 6:
        if (R*C) % 6 != 0: return False
        if max(R, C) >= X and min(R, C) >= X-1: return True
    

    return False


def parse():
    """ parse input """

    X, R, C = [int(i) for i in input().split()]

    return X, R, C


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        if result == False:
            result = 'RICHARD'
        else:
            result = 'GABRIEL'
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
