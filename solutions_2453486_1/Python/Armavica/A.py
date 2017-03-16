#! /usr/bin/python -tt

def tictactoe(grid):
    def row_eval(row):
        if row.count("X") == 4:
            return "X"
        elif row.count("X") == 3 and row.count("T") == 1:
            return "X"
        elif row.count("O") == 4:
            return "O"
        elif row.count("O") == 3 and row.count("T") == 1:
            return "O"
        elif row.count(".") > 0:
            return "."
        else:
            return "#"
    cols = ["".join([row[i] for row in grid]) for i in range(4)]
    diags = ["".join([grid[i][i] for i in range(4)]), "".join([grid[3-i][i] for i in range(4)])]
    evals = [row_eval(line) for line in grid+cols+diags]
    if evals.count("X"):
        return "X won"
    elif evals.count("O"):
        return "O won"
    elif evals.count("."):
        return "Game has not completed"
    else:
        return "Draw"


n = input()
for problem_nb in xrange(n):
    grid = []
    for row in range(4):
        grid.append(raw_input())
    try:
        raw_input()
    except EOFError:
        pass
    print "Case #"+str(problem_nb + 1)+":", tictactoe(grid)
