import argparse

class Grid:
    def __init__(self, rows, columns):
        self.R = rows
        self.C = columns
        self.cells = [['.' for c in range(columns)] for r in range(rows)]
    
    def fill_all(self, value):
        newcells = [[value for c in range(self.C)] for r in range(self.R)]
        self.cells = newcells
                
    def to_str(self):
        # replace with string builder tool perhaps
        output_str = ""
        for row in self.cells:
            for x in row:
                output_str += x
            output_str += '\n'
        return output_str
        
    def transpose(self):
        newcells = [[row[c] for row in self.cells] for c in range(self.C)]
        self.cells = newcells

def minesweeper(R, C, M):
    if (C > R):
        # solve the transposed case and transpose back the result
        print("transposing\n")
        possible, grid = minesweeper(C, R, M)
        grid.transpose()
        print("transposing back\n")
        return possible, grid
        
    # grid is at least as tall as it is wide
    print("starting new case\n")
    print("{} rows by {} cols, {} mines\n".format(R, C, M))
    grid = Grid(R, C)
    print(grid.to_str())
    totalcells = R * C
    if (R <= 0 or C <= 0 or M < 0):
        print("error with input\n")
        return False, grid
    if (M >= totalcells):
        print("error with input\n")
        return False, grid
    if (C == 1):
        for i in range(M):
            grid.cells[i][0] = '*'
    elif (M == 0):
        print("no mines, we're home free\n")
        pass
    elif (M == totalcells - 1):
        # hack that only works because we set bottom-right cell to 'c' at end
        grid.fill_all('*')
        print("fillin all except one \n")
    elif (M == totalcells - 2 or M == totalcells - 3 or M == totalcells - 5 or M == totalcells - 7):
        print("stright up fail boii\n")
        return False, grid
    elif (C == 2):
        print("2 by x\n")
        if (M % 2 == 0):
            for i in range(int(M / 2)):
                grid.cells[i][0] = '*'
                grid.cells[i][1] = '*'
        else:
            return False, grid
    elif (C >= 3):
        print("3 by x\n")
        # at least 1 non-mine. 2 not-mine, 3 not-mine, 5 not-mine, 7 
        # not-mine cases already filtered out, so this will pass.
        working_col = 0
        remaining_mines = M
        while (working_col < C - 3 and remaining_mines > 0):
            for i in range(R-2):
                grid.cells[i][working_col] = '*'
                remaining_mines -= 1
                if (remaining_mines == 0):
                    grid.cells[R-1][C-1] = 'c'
                    return True, grid
            grid.cells[0][working_col + 1] = '*'
            remaining_mines -= 1
            if (remaining_mines == 0):
                grid.cells[R-1][C-1] = 'c'
                return True, grid
            grid.cells[0][working_col + 1] = '.'
            grid.cells[R-2][working_col] = '*'
            grid.cells[R-1][working_col] = '*'
            remaining_mines -= 1
            if (remaining_mines == 0):
                grid.cells[R-1][C-1] = 'c'
                return True, grid
            working_col += 1
        for i in range(R-3):
            grid.cells[i][working_col] = '*'
            remaining_mines -= 1
            if (remaining_mines == 0):
                grid.cells[R-1][C-1] = 'c'
                return True, grid
        for row in range(R-3):
            grid.cells[-3][working_col] = '*'
            remaining_mines -= 1
            if (remaining_mines == 0):
                grid.cells[R-1][C-1] = 'c'
                return True, grid
            grid.cells[-3][working_col] = '.'
            grid.cells[row][-2] = '*'
            grid.cells[row][-1] = '*'
            remaining_mines -= 1
            if (remaining_mines == 0):
                grid.cells[R-1][C-1] = 'c'
                return True, grid
        if (remaining_mines >= 1):
            grid.cells[-3][-3] = '*'
        if (remaining_mines >= 3):
            grid.cells[-3][-2] = '*'
            grid.cells[-3][-1] = '*'
        if (remaining_mines >= 5):
            grid.cells[-2][-3] = '*'
            grid.cells[-1][-3] = '*'
        if (remaining_mines == 8):
            grid.cells[-2][-2] = '*'
            grid.cells[-2][-1] = '*'
            grid.cells[-1][-2] = '*'
        if (remaining_mines != 1 and remaining_mines != 3 and 
                remaining_mines != 5 and remaining_mines != 8):
            print("remaining mines: {}".format(remaining_mines))
            print("captin, we gots a prublemmm\n")
    else:
        # we forgot a case
        print("ABORT! ABORT!\n")        
    grid.cells[R-1][C-1] = 'c'
    return True, grid
                    

def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        numCases = int(f_in.readline().strip())
        for i in range(numCases):
            R, C, M = [int(n) for n in f_in.readline().strip().split()]
            
            possible, grid = minesweeper(R, C, M)
            
            if (possible == False):
                result = "Impossible\n"
            else:
                result = grid.to_str()
            outputline = "Case #{}:\n{}".format(i + 1, result)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        