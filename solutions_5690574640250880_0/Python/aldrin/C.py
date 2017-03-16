import sys


def main():

    # Open input file and read number of testcases
    f = open(sys.argv[1], 'r')
    testcases = int(f.readline())

    for i in range(1, testcases+1):
        # read R, C, M
        line = f.readline()
        line = line.rstrip().split(' ')
        R = int(line[0])
        C = int(line[1])
        M = int(line[2])

        print "Case #" + str(i) + ":"

        if M == 0:
            grid = [[False for i in range(C)] for j in range(R)]
            draw_zero(grid, R, C)
            continue

        r = 0
        c = 0
        found = False
        # iterate through all possible starting clicks
        while r < R and c < C and not found: 
            grid = [[False for i in range(C)] for j in range(R)]
            grid_sol = expand(list(grid), R, C, c, r, R*C - M)
            if grid_sol: 
                draw(grid_sol, R, C, c, r)
                found = True
            c += 1
            if c >= C:
                c = 0
                r += 1
        if not found:
            print "Impossible"

def draw_zero(grid, R, C):
    x = 0
    y = 0
    string = ""
    for r in range(R):
        for c in range(C):
            if r == y and c == x:
                string += "c"

            elif grid[r][c] == False:
                string += "."
        string += "\n"
    print string[:-1]


# draw grid
def draw(grid, R, C, x, y):
    string = ""
    for r in range(R):
        for c in range(C):
            if r == y and c == x:
                string += "c"

            elif grid[r][c] == True:
                string += "."
            else:
                string += "*"
        string += "\n"
    print string[:-1]

def expand(grid, R, C, x, y, N):
    if x >= C or x < 0 or y >= R or y < 0:
        return

    num_opened = 1
    #opened = []
    fringe = [(x, y)]
    grid[y][x] = True

    while fringe:
        # pop off fringe
        p = fringe.pop(0) 

        if num_opened == N:
            return grid

        # get neighbors
        neighbors = []
        for dY in range(-1, 2):
            for dX in range(-1, 2):
                neighbor = (p[0] + dX, p[1] + dY)

                if neighbor[0] < C and neighbor[0] >= 0 and neighbor[1] < R and neighbor[1] >= 0 and not grid[neighbor[1]][neighbor[0]]:
                    # neighbor is unopened
                    neighbors.append(neighbor)
                    # open neighbor
                    grid[neighbor[1]][neighbor[0]] = True
                    num_opened += 1

        if num_opened == N:
            # Correct number of boxes expanded
            return grid
        if num_opened < N:
            # keep expanding
            fringe[0:0] = neighbors
        if num_opened > N:
            # too many expanded, revert to last state
            for neighbor in neighbors:
                grid[neighbor[1]][neighbor[0]] = False
                num_opened -= 1
    return None







main()