# 0=empty
# 1=mine
# 2=click here

#prints 2D list in a pretty format for debugging
def matrix_printer(matrix):
    print("you called matrix_printer!  Here is your nice 2d list:")
    for element in matrix:
        print(element)
        #print("")
    #print("")
    return
# converts a 2d-list with dimensions Y by X (vertical, then horizontal)
# into a string so that it can be printed out easily
def make_string_from_2d_array(array):
    s = ""
    for row in array:
        for element in row:
            if (element == 0):
                s = s + "."
            elif (element == 1):
                s = s + "*"
            else:
                s = s + "c"
        s = s + "\n"
    return s



###############################################################################
input = open("C-small-attempt1.in","r")
inputlist = input.readlines()
input.close()

length_input = len(inputlist)
numberofplays = int(inputlist[0])

output = open("C-small-attempt1.out","w")


case = 1
while (case <= numberofplays):
    #print("start of case {}:".format(case))
    game_string = inputlist[case]
    game_list = game_string.split(" ")
    Row = int(game_list[0]) #down dimension
    Col = int(game_list[1]) #right dimension
    Mines = int(game_list[2]) #number of mines
    matrix = [[0 for i in range(Col)] for j in range(Row)]
    
    #output.write("######CASE {}: {} {} {}\n".format(case, Row, Col, Mines))
    ## special case for full board
    if (Mines == Row*Col):
        output.write("Case #{0}:\n{1}\n".format(case, "Impossible"))
        case += 1
        continue
    
    #matrix_printer(matrix)
    
    ######## special case for a 1xC matrix #do i really need?
    ########
    
    Row_counter = Row
    Col_counter = Col
    while(True): #try putting mines on the smaller side filling a whole row
        if(Row_counter <= 0):
            break
        if(Col_counter <= 0):
            break
        #print(Mines)
        if (Row_counter >= Col_counter): #try to fill the bottom row
            if (Mines >= Col_counter):
                for i in range(Col_counter): #set the entire bottom row to mines
                    #print(Row_counter, i)
                    matrix[Row_counter-1][i] = 1
                Mines -= Col_counter
                Row_counter -= 1
                continue
            else:
                break 
        else: #try to fill the rightmost row
            #print(Mines)
            if (Mines >= Row_counter):
                
                for i in range(Row_counter):
                    matrix[i][Col_counter-1] = 1
                Mines -= Row_counter
                Col_counter -= 1
                continue
            else:
                break
    ##
    #at this point, you have a Col_counter by Row_counter matrix to fill with mines.  
    #the following is based on the (possibly incorrect) idea: you can fill from the bottom-right corner as long as you keep two empty spaces to the left and above the location
    if (Mines == 0):#check if solution
        if(Row_counter == 1 and Col_counter == 1):
            matrix[0][0] = 2
            output.write("Case #{0}:\n{1}".format(case, make_string_from_2d_array(matrix)))
            case += 1
            continue  
        if(Row_counter == 1):
            if (Row != 1):
                output.write("Case #{0}:\n{1}\n".format(case, "Impossible"))
                case += 1
                continue
        if(Col_counter == 1):
            if (Col != 1):
                output.write("Case #{0}:\n{1}\n".format(case, "Impossible"))
                case += 1
                continue
        matrix[0][0] = 2
        output.write("Case #{0}:\n{1}".format(case, make_string_from_2d_array(matrix)))
        case += 1
        continue
    #at least one mine remain
    if (Col_counter <= 2):
        output.write("Case #{0}:\n{1}\n".format(case, "Impossible"))
        case += 1
        continue
    if (Row_counter <= 2):
        output.write("Case #{0}:\n{1}\n".format(case, "Impossible"))
        case += 1
        continue
    
    #now 3x3 or more
    possible_fill = Row_counter-2+Col_counter-3
    #print(possible_fill, Mines, Row_counter, Col_counter)
    #matrix_printer(matrix)
    if (Mines > possible_fill): #return impossible
        output.write("Case #{0}:\n{1}\n".format(case, "Impossible"))
        case += 1
        continue
        
    

    # now fill it.
    Row_count_temp = Row_counter
    Col_count_temp = Col_counter
    while(Mines>0):
        if (Col_count_temp >= 3):
            matrix[Row_count_temp-1][Col_count_temp-1] = 1
            Col_count_temp -= 1
            Mines -= 1
        else: 
            break
    Row_count_temp = Row_counter-1
    Col_count_temp = Col_counter        
    while(Mines>0):
        if (Row_count_temp >= 3):
            matrix[Row_count_temp-1][Col_count_temp-1] = 1
            Row_count_temp -= 1
            Mines -= 1
        #else:  #this is not necessary since we made sure already that it is possible to fill the remaining matrix
        #    print("this should be replaced with a write to output, impossible")
        #    break
            

    #at this point, we have a valid solution

    matrix[0][0] = 2
    output.write("Case #{0}:\n{1}".format(case, make_string_from_2d_array(matrix)))


    case += 1
        #   output.write("Case #{0}: {1}\n".format(case, time_to_win))
output.close()












