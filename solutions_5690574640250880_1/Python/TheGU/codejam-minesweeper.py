debug = False

import itertools
from collections import OrderedDict
from pprint import pprint

def print_grid(grid):
    for i in grid:
        print("".join(i))

with open("C-large.in","r") as f:
#with open("input.txt","r") as f:
    with open("out.txt","w") as o:
        count = 0
        for row in f:
            if not count:
                line = row
                count += 1
                continue


            ########################################
            # Solve Problem
            result = ""
            impossible = False
            R, C, M = list(map(int, row.split()))

            # Check Layout
            if R <= C:
                grid_row = R
                grid_col = C
                trans = False
            else:
                grid_row = C
                grid_col = R
                trans = True

            #print(count,row,grid_row,grid_col,trans)
            # possible win strategy
            # 1 3
            # 1
            # c . x

            # 2 3
            # 2
            # c . x
            # . . x

            # 3 3
            # 1
            # c . .
            # . . .
            # . . x
            # 3
            # c . x
            # . . x
            # . . x
            # 5
            # c . x
            # . . x
            # x x x

            # 3 4
            # 1,2
            # c . . . 
            # . . . .
            # . . x x
            # 3
            # c . . x 
            # . . . x
            # . . . x            
            # 4
            # c . . .
            # . . . .
            # x x x x
            # 6
            # c . . x
            # . . . x
            # x x x x


            # Build Grid
            grid = [["." for y in range(grid_col)] for x in range(grid_row)]
            remain_block = grid_row*grid_col-M

            if M == 0:
                pass
            elif remain_block == 1:
                grid = [["*" for y in range(grid_col)] for x in range(grid_row)]
            elif grid_row >= 3 and grid_col >= 3:
                # Put Bomb
                count_row = 0
                count_col = 0
                count_bomb = M

                
                if remain_block >= 9:
                    # sure win with 3*3
                    # try to fill with no error
                    count_row_buffer = 0
                    while count_bomb:
                        #=============
                        #print_grid(grid)                      
                        if count_bomb > 1:
                            # just put in
                            #=============
                            #print("bomb",count_bomb,"cr",count_row,"cc",count_col)
                            if count_row_buffer==0 and grid_row > 3 and count_row < grid_row-3:
                                grid[count_row][count_col] = "*"
                                count_col += 1
                                if count_col == grid_col:
                                    count_col = 0
                                    count_row += 1
                                count_bomb -= 1
                            else:
                                if count_row_buffer == 0:
                                    count_row_buffer = count_row
                                grid[count_row][count_col] = "*"
                                count_row += 1
                                if count_row == grid_row:
                                    if grid_row > 3:
                                        count_row = count_row_buffer
                                    else:
                                        count_row = 0
                                    count_col +=1
                                count_bomb -= 1
                        else:
                            # check to avoid place before edge
                            #=============
                            #print("cr",count_row,"cc",count_col)
                            #print("col",grid_col-count_col)
                            #print("row",grid_row-count_row)
                            if grid_col-count_col==2:
                                grid[count_row+1][0] = "*"
                            elif grid_row-count_row==2:
                                grid[count_row-1][count_col+1] = "*"
                            else:
                                grid[count_row][count_col] = "*"
                            break

                elif 9-remain_block in  [1,3,5]:
                    # fill all until last 3*3
                    for t_i in range(grid_row-3):
                        for t_j in range(grid_col):
                            grid[t_i][t_j] = "*"
                    for t_i in range(grid_row):
                        for t_j in range(grid_col-3):
                            grid[t_i][t_j] = "*"                            
                    # fill last 3*3                           
                    if 9-remain_block >= 5 :
                        grid[grid_row-2][grid_col-3] = "*"
                        grid[grid_row-1][grid_col-3] = "*"
                    if 9-remain_block >= 3:
                        grid[grid_row-3][grid_col-2] = "*"
                        grid[grid_row-3][grid_col-1] = "*"
                    grid[grid_row-3][grid_col-3] = "*"                    
                else:
                    impossible = True
            elif grid_row == 2 and grid_col >= 3 and \
                 int(M/2) < grid_col-1 and M % 2 == 0:
                for t_c in range(int(M/2)):
                    grid[0][t_c] = "*"
                    grid[1][t_c] = "*"
            elif grid_row == 1 and grid_col >= 3 and M < grid_col-1:
                for t_c in range(M):
                    grid[0][t_c] = "*"
            else:
                impossible = True


            grid[grid_row-1][grid_col-1] = "c"

            if debug:
                print("Case #",count,":",R,C,M)
            if impossible:
                if debug:
                    print("Impossible")
                result = "\nImpossible"
            else:
                if trans:
                    grid = map(list, zip(*grid))
                for i in grid:
                    if debug:
                        print("".join(i))
                    result += "\n" + "".join(i)

                                  
            ########################################
            # Output
            case_result = "Case #%s:%s" % (count,result)
            o.write(case_result+'\n')
            count += 1
