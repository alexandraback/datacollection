file = open("A-small-attempt0.in")
lines = file.readlines()
games = int(lines[0].strip())

def get_game(index):
    game_values = []
    game_start = 1+index*5
    for i in range(game_start, game_start+4):
        game_values.append(list(lines[i].strip()))
    return game_values

# returns 0 if nothing
# returns 1 if X win
# returns 2 if 0 win
def verify_4(values):
    if values.count('T')==1:
        if values.count('X') == 3:
            return 1
        elif values.count('O') == 3:
            return 2
    else:
        if values.count('X') == 4:
            return 1
        elif values.count('O') == 4:
            return 2
    return 0

def solve_game(values):
    # check line by line and row by row
    for i in range(4):
        # verify line
        result = verify_4(values[i])
        if result != 0:
            break
        
        #verify column
        column_values = []
        for j in range(4):
            column_values.append(values[j][i])
        result = verify_4(column_values)
        if result != 0:
            break
            
    if result==1:
        return "X won"
    elif result == 2:
        return "O won"
    
    # check diagonals
    diag1 = []
    diag2 = []
    for i in range(4):
        diag1.append(values[i][i])      
        diag2.append(values[i][3-i])
    
    
    result = verify_4(diag1)
    if result==1:
        return "X won"
    elif result == 2:
        return "O won"
    
    result = verify_4(diag2)
    if result==1:
        return "X won"
    elif result == 2:
        return "O won"
    
    combined = [item for sublist in values for item in sublist]
    if combined.count(".") > 0:
        return "Game has not completed"
    else:
        return "Draw"

out = open("results.out", "w")
for game_index in range(games):
    print >> out,  "Case #"+str(game_index+1)+":", solve_game(get_game(game_index))





