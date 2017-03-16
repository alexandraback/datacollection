import sys
f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    A = []
    grid = []
    A += [map(int,f.readline().split())]
    R = A[0][0]
    C = A[0][1]
    M = A[0][2]
    temprow = R
    tempcol = C
    for i in range(R):
        grid.append([])
        for j in range(C):
            grid[i].append("*")
    free = (R*C)-M
    if R > 2 and C > 2:
        if (free == 2) or (free == 3) or (free == 5) or (free == 7):
            print "Case #%d:" % (t+1)
            print "Impossible"
        else:
            if free == 1:
                grid[0][0] = "c"
            elif free % 2 == 0:
                evenrow = 2
                evencol = 2
                grid[0][0] = "c"
                grid[0][1] = "."
                grid[1][0] = "."
                grid[1][1] = "."
                free = free - 4
                count = 4
                while free > 0 and count < (2*R + 2*C - 4):
                    if temprow > 2:
                        grid[evenrow][0] = "."
                        grid[evenrow][1] = "."
                        temprow = temprow - 1
                        evenrow = evenrow + 1
                        free = free - 2
                        count = count + 2
                    elif tempcol > 2:
                        grid[0][evencol] = "."
                        grid[1][evencol] = "."
                        tempcol = tempcol -1
                        evencol = evencol + 1
                        free = free - 2
                        count = count + 2
                evenrow = 2
                evencol = 2
                while free > 0:
                    if evenrow > R - 1:
                        evenrow = 2
                        evencol = evencol + 1
                    grid[evenrow][evencol] = "."
                    evenrow = evenrow + 1
                    free = free - 1
            else:
                oddrow = 3
                oddcol = 3
                grid[0][0] = "c"
                grid[0][1] = "."
                grid[1][0] = "."
                grid[1][1] = "."
                grid[0][2] = "."
                grid[2][0] = "."
                grid[1][2] = "."
                grid[2][1] = "."
                grid[2][2] = "."
                free = free - 9
                count = 9
                while free > 0 and count < (2*R + 2*C - 3):
                    if temprow > 3:
                        grid[oddrow][0] = "."
                        grid[oddrow][1] = "."
                        temprow = temprow - 1
                        oddrow = oddrow + 1
                        free = free - 2
                        count = count + 2
                    elif tempcol > 3:
                        grid[0][oddcol] = "."
                        grid[1][oddcol] = "."
                        tempcol = tempcol -1
                        oddcol = oddcol + 1
                        free = free - 2
                        count = count + 2
                oddrow = 3
                oddcol = 2
                while free > 0:
                    if oddrow > R - 1:
                        oddrow = 2
                        oddcol = oddcol + 1
                    grid[oddrow][oddcol] = "."
                    oddrow = oddrow + 1
                    free = free - 1
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
    elif R > 2:
        if C == 1:
            grid[0][0] = "c"
            free = free - 1
            count = 1
            while free > 0:
                grid[count][0] = "."
                count = count + 1
                free = free - 1
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)        
        elif free == 1:
            grid[0][0] = "c"
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
        elif free % 2 == 1:
            print "Case #%d:" % (t+1)
            print "Impossible"
        elif free == 2:
            print "Case #%d:" % (t+1)
            print "Impossible"
        else:
            grid[0][0] = "c"
            grid[1][0] = "."
            grid[0][1] = "."
            grid[1][1] = "."
            free = free - 4
            count = 2
            while free > 0:
                grid[count][0] = "."
                grid[count][1] = "."
                count = count + 1
                free = free - 2
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
    elif C > 2:
        if R == 1:
            grid[0][0] = "c"
            free = free - 1
            count = 1
            while free > 0:
                grid[0][count] = "."
                count = count + 1
                free = free - 1
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
        elif free == 1:
            grid[0][0] = "c"
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
        elif free % 2 == 1:
            print "Case #%d:" % (t+1)
            print "Impossible"
        elif free == 2:
            print "Case #%d:" % (t+1)
            print "Impossible"
        else:
            grid[0][0] = "c"
            grid[0][1] = "."
            grid[1][0] = "."
            grid[1][1] = "."
            free = free - 4
            count = 2
            while free > 0:
                grid[0][count] = "."
                grid[1][count] = "."
                count = count + 1
                free = free - 2
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)    
    elif C == 2 and R == 2:
        if free == 1:
            grid[0][0] = "c"
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
        elif free == 4:
            grid[0][0] = "c"
            grid[0][1] = "."
            grid[1][0] = "."
            grid[1][1] = "."
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)            
        else:
            print "Case #%d:" % (t+1)
            print "Impossible"
    elif R == 2:
        if free == 1:
            grid[0][0] = "c"
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)
        elif free == 2:
            grid[0][0] = "c"
            grid[1][0] = "."
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)            
    elif C == 2:
        if free == 1:
            grid[0][0] = "c"
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)            
        elif free == 2:
            grid[0][0] = "c"
            grid[0][1] = "."
            print "Case #%d:" % (t+1)
            for g in grid:
                print ''.join(g)            
    else:
        grid[0][0] = "c"
        print "Case #%d:" % (t+1)
        for g in grid:
            print ''.join(g)
