def solve(X, R, C):
    """ solve the problem """

    #if X >= 7: return False
    #if X > R: return False
    #if X > C: return False
    #if (R * C) % X != 0: return False
    if X == 1:
        return True
    if X == 2:
        if (R * C) % X == 0 : return True
    if X == 3:
        if R == 2 and C == 3: return True
        if R == 3 and C == 2: return True
        if R == 3 and C == 3: return True
        if R == 3 and C == 4: return True
        if R == 4 and C == 3: return True
    if X == 4:
        if R == 3 and C == 4: return True
        if R == 4 and C == 3: return True
        if R == 4 and C == 4: return True

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
