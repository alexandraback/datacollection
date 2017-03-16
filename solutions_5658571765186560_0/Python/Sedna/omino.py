#/usr/bin/python

import sys

def read_input(filename):
    f = open(filename)
    num_cases = int(f.readline())

    omino_size = [0]*num_cases
    x = [0]*num_cases
    y = [0]*num_cases
    for i in range(num_cases):
        myline = f.readline().split()
        omino_size[i] = int(myline[0])
        x[i] = int(myline[1])
        y[i] = int(myline[2])

    f.close()
    return omino_size, x, y

def write_output(filename, solvable):
    f = open(filename,'w')
    
    for i, check in enumerate(solvable):
        f.write("Case #"+str(i+1)+": ")
        if check:
            f.write("GABRIEL\n")
        else:
            f.write("RICHARD\n")

    f.close()
    return

def can_solve(nomino, x, y):
    if nomino > x*y:
        #won't fit ever
        return False

    if x*y % nomino > 0:
        #Can't tile ever -- some spaces always left over
        return False

    if nomino >= 7:
        #In this case, robert can always pick an omino with an
        #unfillable hole
        return False
    
    if nomino == 1 or nomino == 2:
        #Given the above conditions, Gabriel always wins
        return True

    if nomino == 3:
        #Richard can always win if one of x or y == 1
        #By picking the L-omino
        #Otherwise, Gabriel always wins
        if x <= 1 or y <= 1:
            return False
        else:
            return True

    if nomino == 4:
        if x <= 2 or y <= 2:
            # Richard can always win in a 2 by x case by
            # picking the z-shaped 4-omino
            # Hate those in Tetris
            return False
        else:
            return True
        

    if nomino == 5:
        if x <= 2 or y <= 2:
            # Richard can win by picking the "square" V-shaped omino
            return False
        elif min(x,y) == 3:
            if max(x,y) == 5:
                # Or, in a 3x5 case, by picking the "W" omino
                return False
            else:
                # If the larger dimension is at least 10, then even the "W" doesn't cut it
                return True
        else:
            # Otherwise, the 4x5 case works, so all higher cases will, too
            return True

    if nomino == 6:
        if x <= 3 or y <= 3:
            # Richard wins by picking the 3x4 L if either dimension is 2
            # or by picking the box-with-arm shape, which leaves odd
            # numbers of leftover tiles on each side
            return False
        elif x < 6 and y < 6:
            # Richard can win by picking the 1x6 omino
            return False
        else:
            return True

    return True

def can_solve_all(omino_size, x, y):
    solvable = [False]*len(omino_size)

    for i in range(len(omino_size)):
        solvable[i] = can_solve(omino_size[i], x[i], y[i])
        
    return solvable

if __name__ == '__main__':
    filename = sys.argv[1]

    omino_size, x, y = read_input(filename)

    solvable = can_solve_all(omino_size, x, y)

    write_output("output.txt", solvable)
