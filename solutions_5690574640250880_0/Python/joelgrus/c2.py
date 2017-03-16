infile = "C-small-attempt2.in"
outfile = "C-small.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial
from itertools import combinations

num_cases = int(lines[0])
lines = lines[1:]

cases = [[int(x) for x in lines[i].split()] for i in range(num_cases)]

def transpose(matrix):
    num_rows = len(matrix)
    num_cols = len(matrix[0])
    return [[matrix[i][j] for i in range(num_rows)] for j in range(num_cols)]

def neighbors(i,j,rows,cols):
    go_up = i > 0
    go_down = i < rows - 1
    go_left = j > 0
    go_right = j < cols - 1
    
    if go_up:
        yield (i-1,j)
        if go_right: yield (i-1,j+1)
        if go_left: yield (i-1,j-1)
    if go_down:
        yield (i+1,j)
        if go_right: yield(i+1,j+1)
        if go_left: yield(i+1,j-1)
    if go_left:
        yield (i, j - 1)
    if go_right:
        yield (i, j+1)

def create_board(rows, cols, num_pads, mine_locs, double_pad=False):

    actual_rows = [[['.', # me
               0, # adjacent_mines
               False] # explored
              for j in range(cols)] for i in range(rows)]
    # need to add adjacency to last row if padded:
    if num_pads > 0:
        for cell in actual_rows[-1]:
            cell[1] += 1
    pad_rows = [[['*',None,True] for j in range(cols)] for i in range(num_pads)]
    board = actual_rows + pad_rows
    
    if double_pad:
        for i, row in enumerate(board):
            row[-1][1] = 1
            board[i] = row + [['*',None,True] for j in range(num_pads)]
            
    
    for i, j in mine_locs:
        board[i][j][0] = "*"
        for ii, jj in neighbors(i,j,rows,cols):
            board[ii][jj][1] += 1
            
    return board

from collections import deque
    
def try_solve(board, rows, cols, num_mines, click):

    i,j = click
    board[i][j][0] = 'c'
    revealed = 0
    queue = deque([click])
    while queue:
        i, j = queue.popleft()
        cell = board[i][j]
        
        if cell[2]: continue # already visited
        
        # mark as visited
        cell[2] = True
        revealed += 1
        
        if cell[1] > 0:
            continue
            
        # otherwise 0 mines
        # queue up all unvisitedneighbors
        for (ii,jj) in neighbors(i,j,rows,cols):
            if not board[ii][jj][2]:
                queue.append((ii,jj))
        
    success = revealed + num_mines == rows * cols
    return success, board
        
def solve(rows, cols, pad_cols, mines, double_pad = False):
    #print "solve"
    coordinates = [(i,j) for i in range(rows) for j in range(cols)]
    
    #print coordinates
    non_mines = rows * cols - mines
    
    if non_mines >= mines:
    
        mine_locations = combinations(coordinates,mines)
        
        if mines > 0:
        
            for locs in mine_locations:
                loc_set = set(locs)
                for click in coordinates:
                    if click not in loc_set:
                        board = create_board(rows, cols, pad_cols, locs, double_pad)
                        success, grid = try_solve(board, rows, cols, mines, click)
                
                        if success:
                            #print "success", click
                            return grid
                    
            return None

            
        else: # mines = 0
        
            #print "mines == 0"
        
            for click in coordinates:
                board = create_board(rows, cols, pad_cols, [], double_pad)
                #print board
                success, grid = try_solve(board, rows, cols, mines, click)
        
                if success:
                    #print "success", click
                    return grid
            return None
            
    else: # mines > non_mines
    
        #print "allocating",non_mines,"non-mines instead"
        non_mine_locations = combinations(coordinates, non_mines)
        for non_mine_locs in non_mine_locations:
            non_mine_loc_set = set(non_mine_locs)
            locs = [pair for pair in coordinates if pair not in non_mine_loc_set]
            loc_set = set(locs)
            for click in non_mine_locs:
                board = create_board(rows, cols, pad_cols, locs, double_pad)
                success, grid = try_solve(board, rows, cols, mines, click)
        
                if success:
                    #print "success", click
                    return grid
            

            
def pretty(grid, need_to_transpose):
    if grid is None:
        return "Impossible"

    if need_to_transpose:
        return "\n".join(["".join([cell[0] for cell in row]) for row in transpose(grid)])
    else:
        return "\n".join(["".join([cell[0] for cell in row]) for row in grid])

def double_pad(case):
    rows, cols, mines = case
    
    num_pads = 0
    
    while mines >= cols + rows - 1:
        num_pads += 1
        mines -= (cols + rows - 1)
        rows -= 1
        cols -= 1
        
    #print rows, cols, num_pads, mines
    solution = solve(rows, cols, num_pads, mines, double_pad = True)

    return solution
    
def pro_case(case, need_to_transpose=False, use_padding=True):

    rows, cols, mines = case
    #print
    #print rows, cols, mines
    
    # want to chew up rows, i.e. want cols <= rows


    if need_to_transpose:
        rows, cols = cols, rows
        
    # now cols <= rows for sure

    num_pads = 0

    if use_padding:
        while mines >= cols:
            num_pads += 1
            mines -= cols
            rows -= 1
            
    solution = solve(rows, cols, num_pads, mines)
    
    return solution                
    
def process_case(case):
    # first try non-transposed:
    rows, cols, mines = case

    result = pro_case(case,False)
    if result is not None:
        return pretty(result,False)

    transposed_result = pro_case(case,True) if rows != cols else None        
    if transposed_result is not None:
        return pretty(transposed_result,True)

    double_pad_result = double_pad(case)
    if double_pad_result is not None:
        return pretty(double_pad_result,False)
        
    #    if result is not None:
    #        print "double_pad succeeded", case
    #        print pretty(result,False)
    #    else:
    #        #print "trying to brute", case
    #brute_force_result = pro_case(case,use_padding=False)
    #        if result is not None:
    #            print "brute force succeeded!", case
    #            print pretty(result,false)

    #normal = result is not None
    #transposed = transposed_result is not None
    #double_padded = double_pad_result is not None
    #fast_way = any([normal, transposed, double_padded])
    #brute_forced = brute_force_result is not None
    
    #print "(",normal, transposed,double_padded,")",brute_forced,"-->",(fast_way == brute_forced)

    #if fast_way != brute_forced:
    #    print "failure!!!!!!!"
    
    return pretty(result,False)
    
with open(outfile,"w") as g:
        
    for i, case in enumerate(cases):
        #print i, case
        result = process_case(case)
        g.write("Case #" + str(i + 1) + ":\n")
        #g.write(str(case) + "\n")            
        g.write(result + "\n")
    

