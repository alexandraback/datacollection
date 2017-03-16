in_file = open('DATA.TXT')

XWIN = 0;
OWIN = 1;
DRAW = 2;
NONE = 3;
# split into arrays of games
in_arr = in_file.read().split('\n')
num_games = int(in_arr[0])
games_arr = []
for e in range(num_games): games_arr.append(in_arr[5*e+1:5*e+5])

out = []
game_num = 0
for game in games_arr:
    game_res = NONE
    #check draw
    comp = game[0] + game[1] + game[2] + game[3]
    if not '.' in comp: game_res = DRAW
    #check rows
    for e in game:
        repl = e.replace('T',e[0])
        if repl[0] == repl[1] == repl[2] == repl[3]:
            if repl[0] == 'X': game_res = XWIN
            if repl[0] == 'O': game_res = OWIN
    #check cols
    for e in range(4):
        col = game[0][e] + game[1][e] + game[2][e] + game[3][e]
        repl = col.replace('T',col[0])
        if repl[0] == repl[1] == repl[2] == repl[3]:
            if repl[0] == 'X': game_res = XWIN
            if repl[0] == 'O': game_res = OWIN
    #check diagonals
    diag = game[0][0] + game[1][1] + game[2][2] + game[3][3]
    repl = diag.replace('T',diag[0])
    if repl[0] == repl[1] == repl[2] == repl[3]:
        if repl[0] == 'X': game_res = XWIN
        if repl[0] == 'O': game_res = OWIN
    diag = game[0][3] + game[1][2] + game[2][1] + game[3][0]
    repl = diag.replace('T',diag[0])
    if repl[0] == repl[1] == repl[2] == repl[3]:
        if repl[0] == 'X': game_res = XWIN
        if repl[0] == 'O': game_res = OWIN
    game_num += 1
    if game_res == XWIN: out.append('Case #' + str(game_num) + ': X won')
    if game_res == OWIN: out.append('Case #' + str(game_num) + ': O won')
    if game_res == DRAW: out.append('Case #' + str(game_num) + ': Draw')
    if game_res == NONE: out.append('Case #' + str(game_num) + ': Game has not completed')

for e in out: print e
