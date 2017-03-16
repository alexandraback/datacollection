def inv(x, d, k):
    i = 0
    while 1:
        if x == 0: return i
        x = (x + d) % k
        i += 1

for case in range(input()):
    print "Case #"+str(case+1)+":",
    X, R, C = map(int, raw_input().split())
    #print X, R, C
    R, C = sorted([R, C])
    if X >= 7:
        print "RICHARD"
    elif (R * C) % X != 0:
        print "RICHARD"
    else:
        height = (X+1)/2
        width = X - height + 1
        if height > R or width > C:
            print "RICHARD"
        elif C > width and R > height:
            print "GABRIEL"
        elif X in [1, 2, 3]:
            print "GABRIEL"
        #Likely R == height from now on
        elif height == R == 2 and X == 4:
            """
            .##.
            ##..
            """
            """
            ...##...
            ..##....
            """
            # Wrong parity
            print "RICHARD"
        elif height == R == 3 and X == 5:
            """
            .##..
            ##...
            #....
            """
            """
            ..##.
            .##..
            .#...
            """
            """
            ...##
            ..##.
            ..#..
            """
            """
            ....##....
            ...##.....
            ...#......
            """
            #S, T, L
            splits = [(1, 3), (2, 2), (0, 4)]
            minC = R + max([sum(inv(x, 3, 5) for x in split) for split in splits])
            #minC = 10
            if C < minC:
                print "RICHARD"
            else:
                print "GABRIEL"
        elif height == R == 3 and X == 6:
            """
            .## .#. #.. ###
            ##. ##. ##. #..
            #.. .## .## #..
            #.. .#. .#. #..
            """
            splits = [(1, 5), (3, 3), (2, 4), (0, 6)]
            # All possible splits
            # Wrong parity for some.
            print "RICHARD"
        else:
            print "Uh oh", X, R, C, height, width
