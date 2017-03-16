file = open("C-large.in")
file_out = open("AnswerC.txt", "w")


N = int(file.readline())
for j in range(1, N+1):
    [R, C, M] = [int(x) for x in file.readline().split()]
    file_out.write("Case #" + str(j) + ": " + "\n")

    #FIRST SIMPLE CASE: IT IS A SINGLE CORRIDOR. THIS WILL ALWAYS HAVE A SOLUTION!!!!!!!!"
    if R == 1 or C == 1:
        string = ""
        if R == 1: #We're going across
            string += "c"
            for i in range(R*C-M-1): #-1 to Subtract off the click
                string += "."
            for i in range(M):
                string += "*"
            file_out.write(string + "\n")   
        else: #We're going down
            string = ""
            string += "c\n"
            for i in range(R*C-M -1):
                string += ".\n"
            for i in range(M):
                string += "*\n"
            file_out.write(string)
    elif M == 0: #NO MINES!!!
        file_out.write("c"+"."*(C-1)  + "\n")
        for i in range(1, R):
            file_out.write("."*C + "\n")
    #THIRD SIMPLE CASE: WE HAVE ONLY 1 UNMINED SQUARE WHICH WE SHOULD CLICK
    elif (R*C) - M == 1:
        file_out.write("c"+"*"*(C-1)  + "\n")
        for i in range(R-1):
            file_out.write("*"*C  + "\n")
    #THIRD SIMPLE CASE: ONLY 2 ROWS OR COLUMNS
    elif R == 2 or C == 2:
        if R == 2 and C == 2:
            file_out.write("Impossible\n")
        elif R == 2:
            if M % 2 == 0 and R*C-M != 2:
                #We're going across mostly
                mines_in_each = int(M/2)
                spaces_in_each = C - mines_in_each
                file_out.write("c"+"."*(spaces_in_each-1)+"*"*mines_in_each  + "\n")
                file_out.write("."*spaces_in_each + "*"*mines_in_each  + "\n")
            else:
                file_out.write("Impossible\n")
        elif C == 2:
            if M % 2 == 0 and R*C-M != 2:
                row_to_start_mines = R - int(M/2)
                file_out.write("c.\n")
                for i in range(row_to_start_mines - 1):
                    file_out.write("..\n")
                for i in range(row_to_start_mines, R):
                    file_out.write("**\n")
            else:
                file_out.write("Impossible\n")
    else:
        #Make a grid to figure out a suitable arrangement, if one exists
        grid = [0 for r in range(R)] #How many mines in each row?
        grid_built = False
        #Start with 0 in each row
        if M <= (C*(R-2)) - 2 or M == (C*(R-2)): #In this case, we can easily place them in the later rows
            grid_built = True
            full_rows = int(M/C) #How many full rows of mines will we have at the end?
            partial_row = M%C #How many mines in the partial row?
            #If the partial row has M-1 mines, we will need to move a mine up to the above row
            #Will deal with this after the full rows!
            row_index_to_start_full_rows = R - full_rows
            for i in range(row_index_to_start_full_rows, R):
                grid[i] = C #Make this a full row
            #And now deal with the partial row(s)
            if partial_row > 0:
                if partial_row != C - 1:
                    grid[row_index_to_start_full_rows - 1] = partial_row
                else:
                    grid[row_index_to_start_full_rows - 1] = partial_row - 1
                    grid[row_index_to_start_full_rows - 2] = 1
        elif M == (C*(R-2)) - 1: #This cases is probably covered elsewhere but I can't think where
            if (R*C)-M >= 9:
                grid_built = True
                #In this case, the solution is to fill the rows after 3, and to put 1 in each of the first 2 rows and C-3 in the third row
                grid[0] = 1
                grid[1] = 1
                grid[2] = C - 3
                for i in range(3, R):
                    grid[i] = C       
        #Number of mines left after filling rows after 2 is an even number and there are at least 4 empty slots.
        elif (M - (R-2)*C)% 2 == 0 and (R*C)-M >= 4:
            grid_built = True
            #In this case we want to fill the bottom rows, and then fill some of the top 2
            #Fill the bottom rows
            for i in range(2, R):
                grid[i] = C #Fill the row
            #And now fill the top 2 a bit
            mines_still_left = M - ((R-2)*C)
            mines_in_each = int(mines_still_left/2)
            #We knew it was an even number
            grid[0] = mines_in_each
            grid[1] = mines_in_each
        elif (R*C)-M >= 9:
            #My strategy is to take 3 out of the third row in order to make an even number left
            grid_built = True
            for i in range(3, R):
                grid[i] = C #Fill the row
            grid[2] = C - 3
            mines_still_left = M - ((R-2)*C) + 3
            mines_in_each = int(mines_still_left/2)
            grid[0] = mines_in_each
            grid[1] = mines_in_each
    
        #After all that, did we make a grid at all?
        if grid_built:
            #DO THE PRINTING
            #Print the first row (special case)
            mine_count = grid[0]
            dot_count = C - mine_count - 1
            file_out.write("c"+"."*dot_count + "*"*mine_count + "\n")
            #Print the other rows
            for i in range(1, len(grid)):
                mine_count = grid[i]
                dot_count = C - mine_count
                file_out.write("."*dot_count + "*"*mine_count  + "\n")
        else:
            file_out.write("Impossible\n")
file_out.close()
