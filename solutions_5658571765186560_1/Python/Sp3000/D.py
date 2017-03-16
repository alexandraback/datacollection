def solve(X, R, C):
    # True if Gab win
    if X >= 7:
        return False
    
    if X == 1:
        return True

    if X == 2:
        return (R*C)%2 == 0

    if X == 3:
        if (R*C) % 3 != 0:
            return False

        if R == 1 or C == 1:
            return False

        return True

    if X == 4:
        if (R*C) % 4 != 0:
            return False

        if R == 1 or C == 1:
            return False

        if R == 2 or C == 2:
            """
             ##
            ##
            """
            return False

        return True

    if X == 5:
        if (R*C) % 5 != 0:
            return False

        if R <= 2 or C <= 2:
            # L shaped
            return False

        if (R*C) == 15:
            """
            #
            ##
             ##
            """
            return False

        return True

    if X == 6:
        if (R*C) % 6 != 0:
            return False

        if R <= 3 or C <= 3:
            """
             ##
            ##
             ##
            """
            return False

        return True


with open("D-large.in") as infile:
    with open("D.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            X, R, C = map(int, next(infile).split())

            print("Case #{}: {}".format(case, "GABRIEL" if solve(X, R, C) else "RICHARD"), file=outfile)
            
