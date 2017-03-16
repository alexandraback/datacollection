# code jam qualifier 2013 problem A

# tic tac toe tomek

sXwin = "X won" 
sOwin = "O won"
sDraw = "Draw" 
sPlaying = "Game has not completed"


def result(game):
    # horizontal rows are easy
    rows = game[:]

    # vertical rows
    for i in range(4):
        rows.append([game[j][i] for j in range(4)])

    # top left to bottom right
    rows.append([game[j][j] for j in range(4)])

    # top right to bottom left
    rows.append([game[j][3-j] for j in range(4)])

    foundEmpty = False
    for row in rows:
        if row.count("X") + row.count("T") == 4:
            return sXwin
        elif row.count("O") + row.count("T") == 4:
            return sOwin

    if "".join(game).count(".") == 0:
        return sDraw 
    else:
        return sPlaying

fin = open("A-small-0.in", "r")
fout = open("A-small-0.out", "w")

t = int(fin.readline())
for testCase in xrange(t):
    game = []
    for rowNum in range(4):
        game.append(fin.readline())
    fin.readline()
    
    fout.write( "Case #" + str(testCase+1) + ": " + result(game) + "\n")

fout.close()
