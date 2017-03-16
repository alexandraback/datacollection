import argparse

def solve(row, col, mines):
    '''
    Returns the solution 
    '''
    def pprint(grid):
        for row in grid:
            print ''.join(row)

    def get_neighbours(r,c, grid):
        result = []
        for x in (r-1,r,r+1):
            for y in (c-1,c,c+1):
                if 0 <= y < col and 0 <= x < row and grid[x][y] == '*' and (x,y) != (r,c):
                    yield (x,y)


    def get_remaining(grid):
        flatten = [x for row in grid for x in row]
        empty = [y for y in flatten if y == '*']
        return len(empty)

    def reveal(row,col,grid):
        new_grid = [x[:] for x in grid]
        neighbours = [n for n in get_neighbours(row,col,grid)]
        # print neighbours
        for cellx,celly in neighbours:
            new_grid[cellx][celly] = '.'
        return new_grid, neighbours

    def test_cell(row, col, grid, mines):
        # print "Testing ({},{})".format(row,col)
        # print pprint(grid)
        if get_remaining(grid) == mines:
            return grid
        elif get_remaining(grid) < mines:
            return None
        else:
            grid, neighbours = reveal(row, col, grid)
            for next_x, next_y in neighbours:
                next = test_cell(next_x, next_y, grid, mines)
                if next: return next
            else:
                return None
            
    # If no space for 0-neighbour cell, it's impossible
    # if row*col-mines < 4:
    #     return ["Impossible"]
    # else:
    curr_row = 0
    curr_col = 0
    grid = [['*']*col for _ in range(row)]
    #grid[row][col]
    grid[curr_col][curr_row] = 'c'
    result = test_cell(curr_row, curr_col, grid, mines)
    print "Row:{0} Col:{1} Mines:{2}".format(row, col, mines)
    if result:
        pprint(result)
        return result
    else:
        print "Impossible"
        return ["Impossible"]
        # return result or ["Impossible"]


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        for idx in range(int(inp.readline())):
            row, col, mines = [int(x) for x in inp.readline().split()]
            result = solve(row, col, mines)
            solutions.append("Case #{0}:".format(idx+1))
            for row in result:
                solutions.append(''.join(row))
            # solutions.extend(result)
        
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
